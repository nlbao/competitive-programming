/*
	Author: Nguyen Le Bao
	Email: storm5906@gmail.com
	Date: 1/03/2014
	File: DoublyNode.h
	Class: DoublyNode
*/

#pragma once
#include "myXMLFunctions.h"

using namespace std;



template<class Data>
class DoublyNode {
private:
	Data data;			// any data class
	DoublyNode<Data> *pNext;	// the next node
	DoublyNode<Data> *pPre;	// the pre node

public:
	// Constructor with no arguments
	DoublyNode();

	// Constructor with data
	DoublyNode(const Data &data);

	// Destructor
	~DoublyNode();

	// Set data of node
	void setData(const Data &data);

	// Get data of node
	const Data& getData() const;

	// Get id of node
	int getID() const;

	// Set the next node to the new node with data
	void setNext(const Data &data);

	// Set the next node to an exist node
	void setNext(DoublyNode* &other_node);

	// Get the next node
	DoublyNode* &getNext();

	// Set the pre node to the new node with data
	void setPre(const Data &data);

	// Set the pre node to an exist node
	void setPre(DoublyNode* &other_node);

	// Get the pre node
	DoublyNode* &getPre();

	// Save to XML file
	void DoublyNode<Data>::saveToXML(ostream &os, int nIndentation) const;
};



// Constructor with no arguments
template<class Data>
DoublyNode<Data>::DoublyNode() {
	this->pNext = this->pPre = NULL;
}



// Constructor with data
template<class Data>
DoublyNode<Data>::DoublyNode(const Data &data) {
	this->data = data;
	this->pNext = this->pPre = NULL;
}



// Destructor
template<class Data>
DoublyNode<Data>::~DoublyNode() {
	this->data.Data::~Data();
	DoublyNode<Data>* left = this->getPre(), *right = this->getNext();
	if (left != NULL)
		left->setNext(right);
	if (right != NULL)
		right->setPre(left);
}



// Set data of node
template<class Data>
void DoublyNode<Data>::setData(const Data &data) {
	this->data = data;
}



// Get data of node
template<class Data>
const Data& DoublyNode<Data>::getData() const {
	return this->data;
}



// Get id of node
template<class Data>
int DoublyNode<Data>::getID() const {
	return this->data.getID();
}



// Set the next node to the new node with data
template<class Data>
void DoublyNode<Data>::setNext(const Data &data) {
	this->pNext = new DoublyNode<Data>(data);
}



// Set the next node to an exist node
template<class Data>
void DoublyNode<Data>::setNext(DoublyNode<Data>* &other_node) {
	this->pNext = other_node;
}



// Get the next node
template<class Data>
DoublyNode<Data>*& DoublyNode<Data>::getNext() {
	return this->pNext;
}



// Set the pre node to the new node with data
template<class Data>
void DoublyNode<Data>::setPre(const Data &data) {
	this->pPre = new DoublyNode<Data>(data);
}



// Set the pre node to an exist node
template<class Data>
void DoublyNode<Data>::setPre(DoublyNode<Data>* &other_node) {
	this->pPre = other_node;
}



// Get the pre node
template<class Data>
DoublyNode<Data>*& DoublyNode<Data>::getPre() {
	return this->pPre;
}



// Save to XML file
template<class Data>
void DoublyNode<Data>::saveToXML(ostream &os, int nIndentation) const {
	os << toXML<string>("node", nIndentation++, -1) << endl;

	// data content
	os << toXML<string>("data-content", nIndentation, -1) << endl;
	this->data.saveToXML(os, nIndentation+1);
	os << toXML<string>("data-content", nIndentation, 1) << endl;

	os << toXML<string>("node", nIndentation-1, 1) << endl;
}