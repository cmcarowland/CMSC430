files=(
"data/valid1.txt"
"data/valid2.txt"
"data/valid3.txt"
"data/semantic1.txt"
"data/semantic2.txt"
"data/semantic3.txt"
"data/semantic4.txt"
"data/semantic5.txt"
"data/semantic6.txt"
"data/semantic7.txt"
"data/semantic8.txt"
"data/semantic9.txt"
"data/semantic10.txt"
"data/semantic11.txt"
"data/semantic12.txt"
"data/semantic13.txt"
"data/semantic14.txt"
"data/semantic14B.txt"
"data/semantic14C.txt"
"data/semantic15.txt"
"data/semantic15_list_variable.txt"
"data/semantic15_list_numeric.txt"
"data/semantic15_list_numeric_inline.txt"
"data/semantic15_list_no_variable.txt"
"data/semantic16.txt"
"data/semantic16_widen.txt"
"data/semantic16_function.txt"
"data/semantic16_function_widen.txt"
"data/semantic17.txt"
"data/semantic18.txt"
"data/semantic19.txt"
)

for entry in "${files[@]}"; do
  # Split the entry into file and arguments
  file_and_args=($entry)
  file="${file_and_args[0]}"
  args=("${file_and_args[@]:1}")
  echo "Running test with input file: $file and args: ${args[*]}"
  ./bin/project4.elf < "$file" "${args[@]}"
  echo ""
  sleep 2
done