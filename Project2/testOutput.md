$\color{#00a000}{\scriptsize{\textsf{[==========] }}}$ Running 19 tests from 1 test suite.<br/>
<span style="color:#00a000">[==========] </span>Running 19 tests from 1 test suite.<br/>
<span style="color:#00a000">[----------] </span>Global test environment set-up.<br/>
<span style="color:#00a000">[----------] </span>19 tests from SuppliedTest<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test1<br/>
```

   1  // Function with Arithmetic Expression
   2  
   3  function main returns integer;
   4  begin
   5      7 + 2 * (5  + 4);
   6  end;
   7  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test1.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test1 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test2<br/>
```

   1  // Function with When Statement
   2  
   3  function main returns integer;
   4  begin
   5      when 3 < 2 & 6 < 7, 7 * 2 : 7 + 2;
   6  end;
   7  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test2.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test2 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test3<br/>
```

   1  // Function with a Switch Statement
   2  
   3  function main returns character;
   4      a: integer is 2 * 2 + 1;
   5  begin
   6      switch a is
   7          case 1 => 'a';
   8          case 2 => 'b';
   9          others => 'c';  
  10      endswitch;    
  11  end;
  12  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test3.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test3 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test4<br/>
```

   1  // Function with a List Variable
   2  
   3  function main returns integer;
   4      primes: list of integer is (2, 3, 5, 7);
   5  begin
   6      primes(1) + primes(2);
   7  end;
   8  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test4.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test4 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test5<br/>
```

   1  // Function with a Real and Character Variables and Literals
   2  
   3  function main returns character;
   4      a: real is 7.8e-1;
   5  begin
   6      when a < .45, '\n' : 'A';
   7  end;
   8  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test5.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test5 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test6<br/>
```

   1  // Function with an If Statemnt
   2  
   3  function main a: integer returns integer;
   4  begin
   5      if a < 10 then
   6          1;
   7      elsif a < 20 then
   8          2;
   9      elsif a < 30 then
  10          3;
  11      else
  12          4;
  13      endif; 
  14  end;
  15  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test6.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test6 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test7<br/>
```

   1  // Left and Right Fold Statement
   2  
   3  
   4  function main returns integer;
   5      a: list of integer is (1, 2, 3);
   6  begin
   7      switch a(1) is
   8          case 1 =>
   9              fold right - (2,3, 4) endfold;
  10          case 2 =>
  11              fold left + a endfold;
  12          others =>
  13              0;
  14      endswitch;
  15  end;
  16  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test7.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test7 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test8<br/>
```

   1  // Multiple Integer Variable Initializations
   2  
   3  function main returns integer;
   4      b: integer is 5 + 1 - 4;
   5      c: integer is 2 + 3;
   6  begin
   7      b + 1 - c;
   8  end;
   9  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test8.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test8 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test9<br/>
```

   1  // Single Parameter Declaration
   2  
   3  function main a: integer returns integer;
   4  begin
   5      a + 1;
   6  end;
   7  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test9.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test9 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test10<br/>
```

   1  // Two Parameter Declarations
   2  
   3  function main a: integer, b: real returns real;
   4      c: real is .7;
   5  begin
   6      a + b * c;
   7  end;
   8  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test10.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test10 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test11<br/>
```

   1  // Arithmetic Operators
   2  
   3  function main returns integer;
   4  begin
   5      9 + ~2 - (5 - 1) / 2 % 3 * 3 ^ 1 ^ 2;
   6  end;
   7  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test11.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test11 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test12<br/>
```

   1  // Relational and Logical Operators
   2  
   3  function main returns integer;
   4  begin
   5      when 5 > 8 & 3 = 3 | 9 < 1 & !(3 <> 7) | 6 <= 7 & 3 >= 9, 1 : 0;
   6  end;
   7  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test12.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test12 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test13<br/>
```

   1  // Comprehensive Test with Nested If
   2  
   3  function main a: integer, b: character, c: real returns real;
   4      d: integer is #8e;
   5      e: real is 3.75;
   6      f: character is 'A';
   7      g: list of integer is (1, 3, 5);
   8  begin
   9      if ~a > 5 & a < 1 & !(c = 5.8 | c <> .7E4) then
  10          if c >= 7.5E-2 & c <= 5.2 then
  11              when a >= d, a + 2 - 7.9E+2 / 9 * 4 : 8.9;
  12          elsif g(1) = a ^ 2 % 3 then
  13              a % 2 - 5 / c;
  14          else
  15              fold left + (1, 2, 3) endfold;
  16          endif;
  17       else
  18           fold right - g endfold;
  19       endif;
  20  end;
  21  
  22  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test13.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test13 (1 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Test14<br/>
```

   1  // Comprehensive Test with Nested Switch
   2  
   3  function main a: integer, b: real returns real;
   4      c: integer is 8;
   5      d: real is .7E2;
   6  begin
   7      switch a is
   8           case 1 => a * 2 / d ^ 2;
   9           case 2 => a + 5.3E+2 - b;
  10           case 3 =>
  11               switch d is
  12                   case 1 => a % 2;
  13                   others => 9.1E-1;
  14               endswitch;
  15           case 4 => a / 2 - c;
  16           others => a + 4.7 * b;
  17      endswitch;
  18  end;
  19  

Compiled Successfully!!!
```
<span style="color:#8080ff">[  RESULT  ]	data/test14.txt = 0</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Test14 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Syntax1<br/>
```

   1  // Missing Operator in Expression
   2  
   3  function main returns integer;
   4  begin
   5      8 + 2 9 * 3;    
	 -Syntax Error : syntax error, unexpected INT_LITERAL, expecting ';'
   6  end;
   7  

1 errors found. Compilation Failed!
=========================================================
Lexical Errors.             : 0
Syntactic Errors            : 1
Semantic Errors.            : 0
Duplicate Identifier Errors : 0
Undeclared Identifier Errors: 0

```
<span style="color:#8080ff">[  RESULT  ]	data/syntax1.txt = 1</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Syntax1 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Syntax2<br/>
```

   1  // Error in Function Header, Missing Colon
   2  
   3  function main a integer returns integer;
	 -Syntax Error : syntax error, unexpected INTEGER, expecting ':'
   4      b: integer is 3 * 2;
   5  begin
   6      if a <= 0 then
   7          b + 3;
   8      else
   9          b * 4;
  10      endif;
  11  end;
  12  

1 errors found. Compilation Failed!
=========================================================
Lexical Errors.             : 0
Syntactic Errors            : 1
Semantic Errors.            : 0
Duplicate Identifier Errors : 0
Undeclared Identifier Errors: 0

```
<span style="color:#8080ff">[  RESULT  ]	data/syntax2.txt = 1</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Syntax2 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Syntax3<br/>
```

   1  // Error in Variable Declaration
   2  
   3  function main a: integer returns integer;
   4      b integer is
	 -Syntax Error : syntax error, unexpected INTEGER, expecting ':'
   5          if a > 5 then
   6              a * 3;
   7          else
   8              2 + a;
   9          endif;
  10      c: real is 3.5;
  11  begin
  12      if a <= 0 then
  13          b + 3;
  14      else
  15          b * 4;
  16      endif;
  17  end;
  18  

1 errors found. Compilation Failed!
=========================================================
Lexical Errors.             : 0
Syntactic Errors            : 1
Semantic Errors.            : 0
Duplicate Identifier Errors : 0
Undeclared Identifier Errors: 0

```
<span style="color:#8080ff">[  RESULT  ]	data/syntax3.txt = 1</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Syntax3 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Syntax4<br/>
```

   1  // Multiple Errors, Error in Case Clause and Missing Others Clause
   2  
   3  function main a: integer returns integer;
   4  begin
   5      switch a is
   6           case 1 => a 2;
	 -Syntax Error : syntax error, unexpected INT_LITERAL, expecting ';'
   7           case 2 => 5;
   8      endswitch;
	 -Syntax Error : syntax error, unexpected ENDSWITCH, expecting CASE or OTHERS
   9  end;
  10  

2 errors found. Compilation Failed!
=========================================================
Lexical Errors.             : 0
Syntactic Errors            : 2
Semantic Errors.            : 0
Duplicate Identifier Errors : 0
Undeclared Identifier Errors: 0

```
<span style="color:#8080ff">[  RESULT  ]	data/syntax4.txt = 2</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Syntax4 (0 ms)<br/>
<span style="color:#00a000">[ RUN      ] </span>SuppliedTest.Syntax5<br/>
```

   1  -- Multiple Errors
   2  
   3  function main a integer returns real;
	 -Syntax Error : syntax error, unexpected INTEGER, expecting ':'
   4      b: integer is * 2;
	 -Syntax Error : syntax error, unexpected MULOP
   5      c: real is 6.0;
   6  begin
   7      if a > c then
   8          b + / .4;
	 -Syntax Error : syntax error, unexpected MULOP
   9      else
  10          switch b is
  11              case => 2;
	 -Syntax Error : syntax error, unexpected ARROW
  12              case 2 => c;
  13          endswitch;
	 -Syntax Error : syntax error, unexpected ENDSWITCH, expecting CASE or OTHERS
  14      endif;
  15  end;
  16  

5 errors found. Compilation Failed!
=========================================================
Lexical Errors.             : 0
Syntactic Errors            : 5
Semantic Errors.            : 0
Duplicate Identifier Errors : 0
Undeclared Identifier Errors: 0

```
<span style="color:#8080ff">[  RESULT  ]	data/syntax5.txt = 5</span><br/>
<span style="color:#00a000">[       OK ] </span>SuppliedTest.Syntax5 (0 ms)<br/>
<span style="color:#00a000">[----------] </span>19 tests from SuppliedTest (1 ms total)<br/>
<br/>
<span style="color:#00a000">[----------] </span>Global test environment tear-down<br/>
<span style="color:#00a000">[==========] </span>19 tests from 1 test suite ran. (1 ms total)<br/>
<span style="color:#00a000">[  PASSED  ] </span>19 tests.<br/>
