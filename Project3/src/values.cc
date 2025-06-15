// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the evaluation functions

#include <string>
#include <cmath>

using namespace std;

#include "values.h"
#include "listing.h"

double evaluateArithmetic(double left, Operators operator_, double right) {
	double result;
	switch (operator_) {
		case ADD:
			result = left + right;
			break;
		case SUBTRACT:
			result = left - right;
			break;
		case MULTIPLY:
			result = left * right;
			break;
		case DIVIDE:
			if (right == 0) {
				result = 0; // Handle division by zero
			} else {
				result = left / right;
			}
			break;
		case POWER:
			result = pow(left, right);
			break;
		case MODULO:
			if (right == 0) {
				result = 0; // Handle modulo by zero
			} else {
				result = fmod(left, right);
			}
			break;
	}
	return result;
}

double evaluateRelational(double left, Operators operator_, double right) {
	double result;
	switch (operator_) {
		case LESS:
			result = left < right;
			break;
	}
	return result;
}