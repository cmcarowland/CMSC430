/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 3
	July 20, 2025

    values.h
  
    Header file for evaluation functions for arithmetic, relational, and fold operations.
*/

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
