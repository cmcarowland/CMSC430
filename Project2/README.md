# PROJECT 2

## Functionality
1. Parses all syntactically correct programs
   - [x] Include literals for real data type
   - [x] Add if/else/elif statements
   - [x] Create Fold statment
      - [x] Implement direction and operator
   - [x] Implement variable declaration for 0...N variables
   - [x] Implement parameter declarations for function header
      - [x] Allow for comma separated multiple parameters for functions
2. Productions correctly implement precedence and associativity
   - [x] Add binary arithmetic operators for:
      - [x] Mod
      - [x] Exponent
      - [x] unary minus
   - [x] Ensure precedence
3. Grammar contains no shift/reduce or reduce/reduce errors
   - [x] Ensure build completes without shift/reduce
4. Detects and recovers from all programs with single syntax errors
   - [x] Run syntax tests to ensure proper error recovery
5. Detects and recovers from a program with multiple syntax errors
   - [x] Run syntax tests to ensure proper error recovery

---

## Test Cases

1. [x] Includes test cases that test all grammar productions
2. [x] Includes test cases that test errors in all productions
3. [x] Includes test case with multiple errors

<details style="font-size: 1.5rem;">
<summary>Test cases Images</summary>
Test cases 1-5

<img src="images/Tests1-5.png" width="512">

Test cases 6-9

<img src="images/Tests6-9.png" width="512">

Test cases 10-13

<img src="images/Tests10-13.png" width="512">

Test cases 14 and Syntax cases 1 and 2

<img src="images/Test14_S1-2.png" width="512">

Syntax cases 3 and 4

<img src="images/Syntax3-4.png" width="512">

Syntax case 5

<img src="images/Syntax5.png" width="512">
</details>

<details style="font-size: 1.5rem;">
<summary>Google Test Output</summary>

<img src="images/GTest.png" width="512">

</details>
---

### Documentation

1. Discussion of approach included
2. Lessons learned included
3. Comment blocks with student name, project, date and code description included in each file
