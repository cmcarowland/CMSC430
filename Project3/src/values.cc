/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 3
	July 20, 2025

	values.cc

	Implements evaluation functions for arithmetic, relational, and fold operations.
	Handles various operators and edge cases like division by zero.
*/

#include <string>
#include <cmath>
#include <vector>

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
		case LESS_EQ:
			result = left <= right;
			break;
		case GREATER:
			result = left > right;
			break;
		case GREATER_EQ:
			result = left >= right;
			break;
		case NOT_EQUAL:
			result = left != right;
			break;
		case EQUAL:
			result = left == right;
			break;
		case NOT:
			result = !(left == right);
			break;
		case AND:
			result = (left != 0) && (right != 0);
			break;
		case OR:
			result = (left != 0) || (right != 0);
			break;
	}
	return result;
}

double evaluateFold(Direction direction, Operators operator_, vector<double>* list) {	
	if (list->empty()) return NAN;
	
	double result = 0;
	if(direction == Direction::FOLD_RIGHT) 
	{
		result = list->back(); 
	
		for (int i = list->size() - 2; i >= 0; i--) {
			double current = (*list)[i];
			result = evaluateArithmetic(current, operator_, result);
		}
	}
	else
	{
		result = list->front();
		for (int i = 1; i < list->size(); i++) {
			double current = (*list)[i];
			result = evaluateArithmetic(result, operator_, current);
		}
	}

	return result;
}
