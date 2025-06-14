// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains type definitions and the function
// definitions for the evaluation functions

typedef char* CharPtr;

enum Operators {ADD, MULTIPLY, POWER, MODULO, AND, OR, LESS, GREATER, EQUAL, LESS_EQ, GREATER_EQ, NOT_EQUAL, NOT, NEGATE, UNKNOWN};

double evaluateArithmetic(double left, Operators operator_, double right);
double evaluateRelational(double left, Operators operator_, double right);

