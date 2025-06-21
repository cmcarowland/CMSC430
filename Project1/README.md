# PROJECT 1

---

## Lexical Analyzer (`scanner.l`) Modifications

1. [x] **Add Reserved Words**  
   Add the following reserved words as separate tokens (token name = lexeme in all uppercase):  
   - else
   - elsif
   - endfold
   - endif
   - fold
   - if
   - left
   - real
   - right
   - then

2. [x] **Add Logical Operators**  
   - `|` → Token: `OROP`
   - `!` → Token: `NOTOP`

3. [x] **Add Relational Operators**  
   - `=`, `<>`, `>`, `>=`, `<=`  
   All use the token: `RELOP`

4. [x] **Add Subtraction Operator to `ADDOP`**  
   - `-` (subtraction operator)

5. [x] **Add Division Operator to `MULOP`**  
   - `/` (division operator)

6. [x] **Add Remainder Operator**  
   - `%` → Token: `REMOP`

7. [x] **Add Exponentiation Operator**  
   - `^` → Token: `EXPOP`

8. [x] **Add Unary Minus Operator**  
   - `~` → Token: `NEGOP`

9. [x] **Add Line Comment**  
   - Begins with `--` and ends at end of line  
   - No token should be returned

10. [x] **Modify Identifier Definition**  
    - [x] Underscores allowed, but no more than two consecutive underscores  
    - [x] No leading or trailing underscores

11. [x] **Add Hexadecimal Integer Literals**  
    - [x] Begin with `#` followed by one or more decimal digits or letters A-F (upper/lowercase)

12. [x] **Add Real Literal Token**  
    - [x] Begins with zero or more digits, a decimal point, one or more digits  
    - [x] Optional exponent: `e` or `E`, optional `+` or `-`, one or more digits

13. [x] **Expand Character Literals**  
    - Allow escape characters: `\b`, `\t`, `\n`, `\r`, `\f`

> **Note:**  
> You must also modify the header file `tokens.h` to include all new tokens above.

---

## Compilation Listing Generator Modifications

1. [x] **Modify `lastLine` Function**  
   - [x] Compute total number of errors  
   - [x] If errors occurred, display number of lexical, syntactic, and semantic errors  
   - [x] If no errors, display "Compiled Successfully"  
   - [x] Return total number of errors

2. [x] **Modify `appendError` Function**  
   - [x] Count number of lexical, syntactic, and semantic errors  
   - [x] Add error message to a queue for that line

3. [x] **Modify `displayErrors` Function**  
   - Display all error messages for the previous line  
   - Clear the queue of messages

---

### Documentation
- [ ] Doc for project
    - [ ] A discussion of how you approached the project
    - [ ] A test plan that includes test cases that you have created indicating what aspects of the program each one is testing and a screen shot of your compiler run on that test case
    - [ ] A discussion of lessons learned from the project and any improvements that could be made
- [ ] Testing
    - [ ] Create Tests
    - [ ] Test Plan