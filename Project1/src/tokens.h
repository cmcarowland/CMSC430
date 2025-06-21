/* 
   Raymond Rowland
   CMSC 430 Compiler Theory and Design
   Project 1 
   6/20/25

    This header file defines the tokens used in the compiler's lexer.
    It includes token types for operators, keywords, identifiers, literals,
    and additional tokens specific to the project requirements.
*/

enum Tokens {
    ADDOP = 256, 
    MULOP, 
    ANDOP, 
    RELOP, 
    ARROW, 
    BEGIN_, 
    CASE, 
    CHARACTER, 
    END,
    ENDSWITCH, 
    FUNCTION, 
    INTEGER, 
    IS, 
    LIST, 
    OF, 
    OTHERS, 
    RETURNS, 
    SWITCH, 
    WHEN,
    IDENTIFIER, 
    INT_LITERAL, 
    CHAR_LITERAL,
// Additional tokens for the project
    ELSE,
    ELSIF,
    ENDFOLD,
    ENDIF,
    FOLD,
    IF,
    LEFT,
    REAL,
    RIGHT,
    THEN,
    REAL_LITERAL,
    OROP,
    NOTOP,
    REMOP,
    EXPOP,
    NEGOP
};
