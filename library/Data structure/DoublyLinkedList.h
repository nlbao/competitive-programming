/*
	Author: Nguyen Le Bao
	Email: storm5906@gmail.com
	Date: 11/03/2014
	File: DoublyLinkedList.h
	Class: DoublyLinkedList
*/

#pragma once

#include <iostream>
#include <fstream>
#include <typeinfo>
#include "DoublyNode.h"
#include "myXMLFunctions.h"

using namespace std;



template<class Data>
class DoublyLinkedList {
private:
	DoublyNode<Data>* first;	// first node
	DoublyNode<Data>* last;	// last node
	int size;			// size of list


public:
	// Constructor with no arguments
	DoublyLinkedList();

	// Constructor with one node
	DoublyLinkedList(DoublyNode<Data>* node);

	// Constructor with one data element
	DoublyLinkedList(Data &element);

	// Constructor with an array of elements
	DoublyLinkedList(Data* first_element, Data* last_element);

	// Output all node (only id)
	void outputAllID();

	// Get first node
	DoublyNode<Data>* getFirst();

	// Get last node
	DoublyNode<Data>* getLast();

	// Append an element into the linked list
	bool append(const Data &element);

	// Prepend an element into the linked list
	bool prepend(const Data &element);

	// Find a node in the linked list.
	// User will enter student id
	DoublyNode<Data>* findDoublyNode(int id);

	// Sort the linked list ascendingly (by student id)
	void sort();

	// Insert an element after specific node in linked list.
	// User will enter student id to find the node
	// and after that, will enter student info of the inserted node.
	int insertAfter(int id, Data &element);

	// Remove the first node
	void removeFirst();

	// Remove the last node
	void removeLast();

	// Remove node by id
	bool removeByID(int id);

	// Empty linked list
	void erase();

	// Get size of list
	int getSize();

	// Save to XML
	void saveToXML(ostream &os, int nIndentation = 0);
};



// Constructor with no arguments
template<class Data>
DoublyLinkedList<Data>::DoublyLinkedList() {
	this->first = this->last = NULL;
	this->size = 0;
}



// Constructor with one node
template<class Data>
DoublyLinkedList<Data>::DoublyLinkedList(DoublyNode<Data>* node) {
	this->first = this->last = node;
	this->size = 1;
}



// Constructor with one data element
template<class Data>
DoublyLinkedList<Data>::DoublyLinkedList(Data &element) {
	this->first = this->last = new DoublyNode<Data>(element);
	this->size = 1;
}



// Constructor with an array of elements
template<class Data>
DoublyLinkedList<Data>::DoublyLinkedList(Data* first_element, Data* last_element) {
	for(; first_element != last_element; ++first_element)
		append(*first_element);
}



// Output all node (only id)
template<class Data>
void DoublyLinkedList<Data>::outputAllID() {
	for (DoublyNode<Data>* p = this->first; p != NULL; p = p->getNext())
		cout << p->getID() << " ";
	cout << endl;
}



// Get first node
template<class Data>
DoublyNode<Data>* DoublyLinkedList<Data>::getFirst() {
	return this->first;
}



// Get last node
template<class Data>
DoublyNode<Data>* DoublyLinkedList<Data>::getLast() {
	return this->last;
}



// Append an element into the linked list
template<class Data>
bool DoublyLinkedList<Data>::append(const Data &element) {
	DoublyNode<Data> *p = new DoublyNode<Data>(element);
	if (findDoublyNode(p->getID()) != NULL)
		return false;
	if (this->first == NULL) {
		this->first = this->last = p;
		this->size = 1;
		return true;
	}
	p->setPre(this->last);
	this->last->setNext(p);
	this->last = p;
	++this->size;
	return true;
}



// Prepend an element into the linked list
template<class Data>
bool DoublyLinkedList<Data>::prepend(const Data &element) {
	DoublyNode<Data> *p = new DoublyNode<Data>(element);
	if (findDoublyNode(p->getID()) != NULL)
		return false;
	if (this->size == 0) {
		this->first = this->last = p;
		this->size = 1;
		return true;
	}
	p->setNext(this->first);
	this->first->setPre(p);
	this->first = p;
	++this->size;
	return true;
}



// Find a node in the linked list.
// User will enter student id
template<class Data>
DoublyNode<Data>* DoublyLinkedList<Data>::findDoublyNode(int id) {
	for (DoublyNode<Data>* p = this->first; p != NULL; p = p->getNext())
		if (p->getID() == id)
			return p;
	return NULL;
}



// Sort the linked list ascendingly (by student id)
template<class Data>
void DoublyLinkedList<Data>::sort() {
	//sub_sort(this->first, this->first);
	for (DoublyNode<Data>* p = this->first; p != NULL; p = p->getNext())
		for (DoublyNode<Data>* q = p->getNext(); q != NULL; q = q->getNext())
			if (q->getID() < p->getID()) {
				Data tmp = p->getData();
				p->setData(q->getData());
				q->setData(tmp);
			}
}



// Insert an element after specific node in linked list.
// User will enter student id to find the node
// and after that, will enter student info of the inserted node.
template<class Data>
int DoublyLinkedList<Data>::insertAfter(int id, Data &element) {
	DoublyNode<Data>* p = findDoublyNode(id);
	if (p == NULL)
		return -1;

	DoublyNode<Data>* new_node = new DoublyNode<Data>(element);
	if (findDoublyNode(new_node->getID()) != NULL)
		return 0;

	DoublyNode<Data>* q = p->getNext();
	if (q != NULL) {
		new_node->setNext(q);
		q->setPre(new_node);
	}
	p->setNext(new_node);
	return 1;
}



// Remove the first node
template<class Data>
void DoublyLinkedList<Data>::removeFirst() {
	if (this->first == NULL)
		return;
	DoublyNode<Data>* p = this->first->getNext();
	delete this->first;
	this->first = p;
	--this->size;
}



// Remove the last node
template<class Data>
void DoublyLinkedList<Data>::removeLast() {
	if (this->last == NULL)
		return;
	DoublyNode<Data>* p = this->last->getPre();
	delete this->last;
	this->last = this->last = p;
	--this->size;
}



// Remove node by id
template<class Data>
bool DoublyLinkedList<Data>::removeByID(int id) {
	DoublyNode<Data>* p = findDoublyNode(id);
	if (p == NULL)
		return false;
	if (this->first == p)
		first = p->getNext();
	if (this->last == p)
		last = p->getPre();
	delete p;
	--this->size;
	return true;
}



// Empty linked list
template<class Data>
void DoublyLinkedList<Data>::erase() {
	for (DoublyNode<Data>* p = this->first, *q; p != NULL; p = q) {
		q = p->getNext();
		delete p;
	}
	this->first = NULL;
	this->size = 0;
}



// Get size of list
template<class Data>
int DoublyLinkedList<Data>::getSize() {
	return this->size;
}



// Save to XML file
template<class Data>
void DoublyLinkedList<Data>::saveToXML(ostream &os, int nIndentation) {
	os << toXML<string>("linked-list", nIndentation++, -1) << endl;

	// data type
	os << toXMLelement<string>("data-type", typeid(Data).name(), nIndentation);
	// size
	os << toXMLelement<int>("size", this->size, nIndentation);
	// nodes
	for (DoublyNode<Data>* p = this->first; p != NULL; p = p->getNext())
		p->saveToXML(os, nIndentation);

	os << toXML<string>("linked-list", nIndentation-1, 1) << endl;
}
