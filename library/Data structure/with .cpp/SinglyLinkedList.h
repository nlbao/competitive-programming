/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: SinglyLinkedList.h
*/

#pragma once
#define _RSSinglyLinkedList_

#include "SinglyNode.h"
#include <cstddef>	// to use NULL



template<class Data>
class SinglyLinkedList {
private:
	SinglyNode<Data>* _last;	// last node
	int _size;	// size of list


public:
	// Constructor with no arguments
	SinglyLinkedList();

	// Constructor with one node
	SinglyLinkedList(SinglyNode<Data>* node);

	// Constructor with one data element
	SinglyLinkedList(Data &element);

	// Constructor with an array of elements
	SinglyLinkedList(Data* first_element, Data* last_element);

	// Destructor
	~SinglyLinkedList();

	// Get last node
	SinglyNode<Data>* last();

	// Append an element into the linked list
	void append(const Data &element);

	// Remove the last node
	void removeLast();

	// Empty linked list
	void clear();

	// Get size of list
	int size();
};



#include "SinglyLinkedList.cpp"