/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	types.h

	Header file defining Types enumeration and type checking function prototypes.
	Declares interfaces for type compatibility validation, assignment checking,
	and semantic analysis functions used throughout the compiler's type system.
*/

#ifndef TYPES_H
#define TYPES_H

typedef char* CharPtr;

enum Types {MISMATCH, INT_TYPE, CHAR_TYPE, REAL_TYPE, NONE};

Types checkAssignment(Types lValue, Types rValue, string message);
Types checkWhen(Types true_, Types false_);
Types checkSwitch(Types case_, Types when, Types other);
Types checkCases(Types left, Types right);
Types checkArithmetic(Types left, Types right);

Types checkList(Types defined, Types expression);
Types checkListItem(Types left, Types right);

Types checkSubscript(Types type);

bool checkRelopTypes(Types left, Types right);

Types checkNumericType(Types type);

Types checkMod(Types left, Types right);

void cacheIf(Types type);
Types areSameTypes(Types other);
void clearCache();

bool isNumericType(Types type);
Types checkFold(Types type);

#endif // TYPES_H