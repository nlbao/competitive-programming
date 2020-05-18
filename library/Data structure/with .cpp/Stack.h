/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: Stack.h
*/

#pragma once
#define _RSStack_

#include <cstddef>	// to use NULL
#include "SinglyNode.h"



template<class Data>
class Stack {
private:
	SinglyNode<Data>* _top;	// top node
	int _size;			// size of list


public:
	// Constructor with no arguments
	Stack();

	// Constructor with one node
	Stack(SinglyNode<Data>* node);

	// Constructor with one data element
	Stack(const Data &element);

	// Constructor with an array of elements
	Stack(Data* first_element, Data* last_element);

	// Push	a node on top of stack
	void push(const Data &element);

	// Pop the top node
	const Data& pop();

	// Get the top node (but doesn't remove it)
	const Data& top() const;

	// Empty stack
	void clear();

	// Get size of list
	int size() const;

	// Chec if stack is empty
	bool is_empty() const;
};



#include "Stack.cpp"