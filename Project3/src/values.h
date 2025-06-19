// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// definitions for the evaluation functions

typedef char* CharPtr;

enum Operators {
    ADD,
    MULTIPLY,
    SUBTRACT,
    DIVIDE,
    POWER,
    MODULO,
    NEGATE,
    // Logical operators
    AND,
    OR,
    // Relational operators
    LESS,
    LESS_EQ,
    GREATER,
    GREATER_EQ,
    NOT_EQUAL,
    NOT,
    EQUAL,
    UNKNOWN
};

enum Direction {
    FOLD_LEFT,
    FOLD_RIGHT
};

double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);
double evaluateFold(Direction, Operators, vector<double>*);
