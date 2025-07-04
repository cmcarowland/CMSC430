class Color:
    def __init__(self, name, code, hexColor):
        self.name = name
        self.code = code
        self.hex = hexColor

    def __str__(self):
        return f"{self.code}{self.name}{RESET}"

colors = {
    'GREEN': Color('green', '\x1b[0;32m', '#00a000'),
    'RED': Color('red', '\x1b[0;31m', '#ff4040'),
    'LIGHT_BLUE': Color('lightblue', '\x1b[94m', '#8080ff'),
    'RESET': Color('', '\x1b[m', '')
}

inCodeSection = False

def wrap_color(text, color):
    startColor = text.find(color.code)
    endColor = text.find(colors['RESET'].code) - len(colors['RESET'].code) - len(color.code)
    text = text.replace("\n", "")
    text = text.replace(color.code, "")
    text = text.replace(colors['RESET'].code, "")
    return f'<span style="color:{color.hex}">{text[startColor:endColor+3]}</span>' + text[endColor+3:]

def check_start_code(line):
    global inCodeSection
    if line.find("[ RUN      ]") != -1:
        inCodeSection = True

def wrap_code(text):
    global inCodeSection

    s = f'```\n'
    for l in text:
        s += f'{l}'
    s += '```'
    inCodeSection = False
    return s    

with open("Project2/testOutput.txt", 'r') as iFile:
    lines = iFile.readlines()

with open("Project2/testOutput.md", 'w') as oFile:
    i = 0
    while i < len(lines):
        line = lines[i]
        check_start_code(line)
        if line.startswith(colors['GREEN'].code):
            oFile.write(wrap_color(line, colors['GREEN']) + '<br/>\n')
        elif line.startswith(colors['RED'].code):
            oFile.write(wrap_color(line, colors['RED']) + '<br/>\n')
        elif line.startswith(colors['LIGHT_BLUE'].code):
            oFile.write(wrap_color(line, colors['LIGHT_BLUE']) + '<br/>\n')
        else:
            if not inCodeSection:
                oFile.write(line.strip() + '<br/>\n')
            else:
                start = i
                end = i + 1
                while lines[end].find("[  RESULT  ]") == -1:
                    end += 1
                    if end >= len(lines):
                        break
                i = end - 1
                oFile.write(wrap_code(lines[start:end]) + '\n')
        i += 1
