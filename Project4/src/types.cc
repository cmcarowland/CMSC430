/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	types.cc

	Implementation of type checking functions for the compiler.
	Handles type compatibility validation, assignment checking, arithmetic operations,
	and semantic analysis for various language constructs including when statements and switch cases.
*/

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"
#include "error.h"

Types currentType;

Types checkAssignment(Types expectedType, Types returnedType, string message) {
	// printf("checkAssignment(%d, %d)\n", expectedType, returnedType);
	if (returnedType == MISMATCH || returnedType == NONE)
		return MISMATCH;
	
	if(expectedType == returnedType)
		return returnedType;

	if(expectedType == INT_TYPE && returnedType == REAL_TYPE)
		appendError(GENERAL_SEMANTIC, "Illegal Narrowing " + message);
	else if(isNumericType(expectedType) && !isNumericType(returnedType))
		appendError(GENERAL_SEMANTIC, " Type Mismatch on " + message);

	return MISMATCH;
}

Types checkWhen(Types true_, Types false_) {
	if (true_ == MISMATCH || false_ == MISMATCH)
		return MISMATCH;
	if (true_ != false_)
		appendError(GENERAL_SEMANTIC, "When Types Mismatch ");

	return true_;
}

Types checkSwitch(Types case_, Types when, Types other) {
	if (case_ != INT_TYPE)
		appendError(GENERAL_SEMANTIC, "Switch Expression Not Integer");
	return checkCases(when, other);
}

Types checkCases(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	if (left == NONE || left == right)
		return right;

	appendError(GENERAL_SEMANTIC, "Case Types Mismatch");
	return MISMATCH;
}

Types checkArithmetic(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;
	
	if (checkNumericType(left) == MISMATCH || checkNumericType(right) == MISMATCH)
		return MISMATCH;

	if (left == right)
		return right;
	else
	{
		if (left == REAL_TYPE && right == INT_TYPE)
			return REAL_TYPE;
		
		if (right == REAL_TYPE && left == INT_TYPE)
			return REAL_TYPE;
	}

	
	appendError(GENERAL_SEMANTIC, "Integer Type Required");
	return MISMATCH;
}

Types checkList(Types defined, Types expression) {
	if (expression == MISMATCH)
		return MISMATCH;

	if (defined == expression)
		return defined;

	appendError(GENERAL_SEMANTIC, "List Elements Do Not Match Defined Type");
	return MISMATCH;
}

Types checkListItem(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;

	if (left == NONE || left == right)
		return right;


	appendError(GENERAL_SEMANTIC, "List element type mismatch");
	return MISMATCH;
}

Types checkSubscript(Types type)
{
	if (type == MISMATCH)
		return MISMATCH;

	if (type == INT_TYPE)
		return INT_TYPE;

	appendError(GENERAL_SEMANTIC, "Subscripted Type Must Be Integer");
	return MISMATCH;
}

bool checkRelopTypes(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return false;

	if(left == INT_TYPE && right == CHAR_TYPE) {
		appendError(GENERAL_SEMANTIC, "Character Literals Cannot be Compared to Numeric Expressions");
		return false;
	}

	
	if(left == CHAR_TYPE && right == INT_TYPE) {
		appendError(GENERAL_SEMANTIC, "Character Literals Cannot be Compared to Numeric Expressions");
		return false;
	}

	return true;
}

Types checkNumericType(Types type) {
	if (type == MISMATCH)
		return MISMATCH;

	if (isNumericType(type))
		return type;

	appendError(GENERAL_SEMANTIC, "Arithmetic Operations Require Numeric Types");
	return MISMATCH;
}

Types checkMod(Types left, Types right) {
	if (left == MISMATCH || right == MISMATCH)
		return MISMATCH;

	if (left != INT_TYPE || right != INT_TYPE) {
		appendError(GENERAL_SEMANTIC, "Remainder Operator Requires Integer Operands");
		return MISMATCH;
	}

	return INT_TYPE;
}

Types areSameTypes(Types right) {
	if (currentType == MISMATCH || right == MISMATCH)
		return MISMATCH;

	if (currentType == right)
		return right;

	currentType = MISMATCH; 
	appendError(GENERAL_SEMANTIC, "If-Elsif-Else Type Mismatch");
	return MISMATCH;
}

void cacheIf(Types type) {
	currentType = type; 
}

void clearCache() {
	currentType = NONE; 
}

bool isNumericType(Types type) {
	if (type == INT_TYPE || type == REAL_TYPE)
		return true;

	return false;
}

Types checkFold(Types type) {
	if (type == MISMATCH)
		return MISMATCH;

	if (isNumericType(type))
		return type;

	appendError(GENERAL_SEMANTIC, "Fold Requires Numeric List");
	return MISMATCH;
}