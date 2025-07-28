// CMSC 430 Compiler Theory and Design
// Project 4 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the type checking functions

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"
#include "error.h"

void checkAssignment(Types lValue, Types rValue, string message) {
	if (lValue != MISMATCH && rValue != MISMATCH && lValue != rValue)
		appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
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
	
	if (left == INT_TYPE && right == INT_TYPE)
	return INT_TYPE;
	
	if (left != right)
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