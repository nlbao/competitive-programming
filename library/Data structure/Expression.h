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

#include <iostream>
//#include <string.h>
#include <cctype>
#include "SinglyLinkedList.h"
#include "Stack.h"

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



// Constructor with no arguments
Expression::Expression() {
	this->_tokens = NULL;
	//this->_tokens = SinglyLinkedList<char*>();
}



// Constructor with a string
Expression::Expression(char* expression) {
	this->_tokens = new SinglyLinkedList<char*>();
	int len = strlen(expression);
	for (int i = len-1, j = i; i >= 0; i = j) {		// reverse
		// find token
		while (i >= 0 && expression[i] == ' ') i = --j;	// skip spaces
		if (i < 0) break;	// end of expression
		while (--j >= 0 && isSameType(expression[i], expression[j]));	// same type characters

		// take and insert new token
		char *new_token = new char[i-j+1];
		for (int k = j+1; k <= i; ++k)
			new_token[k-j-1] = expression[k];
		new_token[i-j] = '\0';
		this->_tokens->append(new_token);
		// cout << "	Token: " << new_token << endl;
	}
}



// Copy constructor
Expression::Expression(const Expression &other) {
	this->_tokens = new SinglyLinkedList<char*>();
	for (SinglyNode<char*>* p = this->_tokens->last(); p != NULL; p = p->getNext())
		this->_tokens->append(p->getData());
}



// Destructor
Expression::~Expression() {
	this->_tokens->SinglyLinkedList::~SinglyLinkedList();
}



// Output the expression
void Expression::output() {
	for (SinglyNode<char*>* p = this->_tokens->last(); p != NULL; p = p->getNext())
		cout << p->getData();
}



// Calculate result of the expression
double Expression::calculate() {
	// Ref: http://en.wikipedia.org/wiki/Reverse_Polish_notation
	// Ref: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
	// First, convert the infix (popular) notation to Reverse Polish notation (RPN)
	// using the Shunting-yar algorithm.
	// Instead of queue of operands, I use the stack to store operands
	// and calculate the RPN.

	// init
	Stack<double> operand;		// stack of operands
	Stack<char> operators;	// stack of operators

	// process
	for (SinglyNode<char*>* p = this->_tokens->last(); p != NULL; p = p->getNext()) {
		char* token = p->getData();
		if (isdigit(token[0]))	// is digit
			operand.push(atof(token));
		else	// is operators or '(' or ')'
			if (token[0] == '(')	// is '('
				operators.push('(');
			else if (token[0] == ')') {		// is ')'
				while (operators.top() != '(')
					if (operand.size() > 1)
						// calculate two operands at the top of operand stack
						// using the operator of the top of operators stack
						operand.push(calOperator(operand.pop(), operand.pop(), operators.pop()));
					else 
						cout << "Error: Missing operand!" << endl;
				operators.pop();	// pop '('
			}
			else {	// is operators
				if (operators.size()
					&& operatorPriority(token[0]) <= operatorPriority(operators.top()))
					// if the priority of the new operator is less than or equal to
					// the priority of the operator at top of operators stack
					if (operand.size() > 1)
						// calculate two operands at the top of operand stack
						// using the operator of the top of operators stack
						operand.push(calOperator(operand.pop(), operand.pop(), operators.pop()));
					else
						cout << "Error: Missing operand!" << endl;
				operators.push(token[0]);
			}
	}
	// calculate remain operands and operators in stacks
	while (operand.size() > 1)
		operand.push(calOperator(operand.pop(), operand.pop(), operators.pop()));
	return operand.top();	// return result
}




/*-----------------------------------Other functions-----------------------------------*/

// return operator's precedence
int operatorPriority(const char &x) {
	for (int i = 0; i < nOPERATOR; ++i)
		if (OPERATOR_LIST[i] == x)
			return OPERATOR_PRIORITY[i];
	return -1;
}



// Check if two token are same type
bool isSameType(const char &x, const char &y) {
	if (x == '.' || y == '.')
		return isdigit(x) || isdigit(y);
	if (y == ' ' || x == '(' || x == ')' || operatorPriority(x) != -1)
		return false;
	if (x == y)
		return true;
	if (isdigit(x) == isdigit(y))
		return true;
	return false;
}



// calculate a expression which has only one binary operator
double calOperator(double x, double y, char oper) {
	switch(oper) {
	case '+':
		return x+y;
		break;
	case '-':
		return x-y;
		break;
	case '*':
		return x*y;
		break;
	case '/':
		return x/y;
		break;
	}
	return -1;
}
