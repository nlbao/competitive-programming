/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: Expression.h
*/

#pragma once

#include "SinglyLinkedList.h"


using namespace std;


// Consts
const int nOPERATOR = 4;
const char OPERATOR_LIST[nOPERATOR] = {'+', '-', '*', '/'};
const int OPERATOR_PRIORITY[nOPERATOR] = {0, 0, 1, 1};


// prototypes
int operatorPriority(const char &x);
bool isSameType(const char &x, const char &y);
double calOperator(double x, double y, char oper);



// class Expression
class Expression {
private:
	SinglyLinkedList<char*>* _tokens;


public:
	// Constructor with no arguments
	Expression();

	// Constructor with a string
	Expression(char* expression);

	// Constructor with an array of elements
	Expression(char* first_element, char* last_element);

	// Copy constructor
	Expression(const Expression &other);

	// Destructor
	~Expression();

	// Output the expression
	void output();

	// Calculate result of the expression
	double calculate();
};
