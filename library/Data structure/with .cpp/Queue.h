/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 02
	Date: 13/03/2014
	File: Queue.h
*/

#pragma once
#define _RSQueue_

#include <cstddef>	// to use NULL
#include "SinglyNode.h"



template<class Data>
class Queue {
private:
	SinglyNode<Data> *_front, *_rear;	// front: delete; rear: insert
	int _size;	// size of queue


public:
	// Constructor with no arguments
	Queue();

	// Constructor with one node
	Queue(SinglyNode<Data>* node);

	// Constructor with one data element
	Queue(const Data &element);

	// Constructor with an array of elements
	Queue(Data* first_element, Data* last_element);

	// Push	a node at the end of queue	
	void enqueue(const Data &element);

	// Pop the first node node
	const Data& dequeue();

	// Get the first node (but doesn't remove it)
	const Data& front() const;

	// Empty queue
	void clear();

	// Get size of queue
	int size() const;

	// Chec if queue is empty
	bool is_empty() const;
};



#include "Queue.cpp"