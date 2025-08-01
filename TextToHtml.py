import re
import sys

'''
Run the following command to generate the testOutput.txt file:
./bin/test.elf --gtest_color=yes > testOutput.txt
The color yes option is important to ensure that the output contains ANSI color codes, which are used to format the HTML output.

Once you have the testOutput.txt file, you can convert it to HTML using:
python TextToHtml.py <path>/testOutput.txt <path>/testOutput.html

'''

pattern = re.compile(r'\[\s+[A-Z]+\s+\]')

header = '''
    <head>
        <style>
            :root {
                --orange: #ff8000;
                --green: #00a000;
                --light-blue: #8080ff;
                --red: #ff4040;
                --background-blue: hsl(240, 100%, 9%);
                font-family: monospace;
            }

            body {background-color: var(--background-blue); color: white;display: flex;flex-direction: column;align-items: center;} 
            div {width: 100%; max-width: 900px;}
            span {margin-left: -50;}
            pre {
                background-color: color-mix(in lab, var(--background-blue), black 50%);
                border-radius: 8px;
                box-shadow: 0 4px 4px rgba(0,0,0,1);
                padding: 10px;
            }
        </style>
    </head>
'''

class Color:
    def __init__(self, name, code, hexColor):
        self.name = name
        self.code = code
        self.hex = hexColor

    def __str__(self):
        return f"{self.code}{self.name}{RESET}"

colors = {
    'GREEN': Color('green', '\x1b[0;32m', 'var(--green)'),
    'RED': Color('red', '\x1b[0;31m', 'var(--red)'),
    'LIGHT_BLUE': Color('lightblue', '\x1b[0;94m', 'var(--light-blue)'),
    'ORANGE': Color('orange', '\x1b[0;33m', 'var(--orange)'),
    'RESET': Color('', '\x1b[m', '')
}

inCodeSection = False

def wrap_color(text, color):
    text = text.replace("\n", "")
    text = text.replace(" ", "&nbsp;")

    colorIndex = text.find(color.code) + len(color.code)
    resetIndex = text.rfind(colors['RESET'].code)
    if resetIndex == -1:
        resetIndex = len(text)

    return f'<span style="color:{color.hex}">{text[colorIndex:resetIndex]}</span>' + text[resetIndex + len(colors['RESET'].code):]

def check_start_code(line):
    global inCodeSection
    if line.find("[ RUN      ]") != -1:
        inCodeSection = True

def wrap_code(text):
    global inCodeSection

    s = f'<pre>\n'
    for l in text:
        s += f'{l}'
    s += '</pre>'
    inCodeSection = False
    return s    

if len(sys.argv) != 3:
    print("Usage: python TextToHtml.py <input_file> <output_file>")
    sys.exit(1)

with open(sys.argv[1], 'r') as iFile:
    lines = iFile.readlines()

with open(sys.argv[2], 'w') as oFile:
    oFile.write(f'<html>{header}\n<body>\n<div>\n')
    i = 0
    while i < len(lines):
        line = lines[i]
        # print(bytes(line.strip(), 'utf-8'))
        check_start_code(line)
        # print(inCodeSection)
        if colors['GREEN'].code in line:
            oFile.write(wrap_color(line, colors['GREEN']) + '<br/>\n')
        elif colors['RED'].code in line:
            oFile.write(wrap_color(line, colors['RED']) + '<br/>\n')
        elif colors['LIGHT_BLUE'].code in line:
            oFile.write(wrap_color(line, colors['LIGHT_BLUE']) + '<br/>\n')
        elif colors['ORANGE'].code in line:
            oFile.write(wrap_color(line, colors['ORANGE']) + '<br/>\n')
        else:
            if not inCodeSection:
                oFile.write(line.strip() + '<br/>\n')
            else:
                start = i
                end = i + 1
                while pattern.search(lines[end]) is None:
                    end += 1
                    if end >= len(lines):
                        break
                i = end - 1
                oFile.write(wrap_code(lines[start:end]) + '\n')

        i += 1

    oFile.write('</div>\n</body>\n</html>\n')
