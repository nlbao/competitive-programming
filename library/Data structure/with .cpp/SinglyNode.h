/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: SinglyNode.h
*/

#pragma once
#define _RSSinglyNode_

#include <cstddef>	// to use NULL


template<class Data>	// any data class
class SinglyNode {
private:
	Data data;			// data
	SinglyNode<Data> *pNext;	// the next node

public:
	// Constructor with no arguments
	SinglyNode();

	// Constructor with data
	SinglyNode(const Data &data);

	// Copy constructor
	SinglyNode(const SinglyNode<Data> &other);

	// Destructor
	~SinglyNode();

	// Set data of node
	void setData(const Data &data);

	// Get data of node
	const Data& getData() const;

	// Set the next node to the new node with data
	void setNext(const Data &data);

	// Set the next node to an exist node
	void setNext(SinglyNode<Data>* &other);

	// Get the next node
	SinglyNode<Data>* &getNext();

	// Check if left node < right node
	bool operator < (const SinglyNode<Data> &other) const;

	// Check if left node == right node
	bool operator == (const SinglyNode<Data> &other) const;

	// Check if left node > right node
	bool operator > (const SinglyNode<Data> &other) const;
};



#include "SinglyNode.cpp"