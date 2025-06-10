// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the enumerated type definition for tokens

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
    HEX_LITERAL,
    OROP,
    NOTOP,
    REMOP
};
