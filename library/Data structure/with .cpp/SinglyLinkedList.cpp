/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: SinglyLinkedList.cpp
*/

#ifdef _RSSinglyLinkedList_



// Constructor with no arguments
template<class Data>
SinglyLinkedList<Data>::SinglyLinkedList() {
	this->_last = NULL;
	this->_size = 0;
}



// Constructor with one node
template<class Data>
SinglyLinkedList<Data>::SinglyLinkedList(SinglyNode<Data>* node) {
	this->_last = node;
	this->_size = 1;
}



// Constructor with one data element
template<class Data>
SinglyLinkedList<Data>::SinglyLinkedList(Data &element) {
	this->_last = new SinglyNode<Data>(element);
	this->_size = 1;
}



// Constructor with an array of elements
template<class Data>
SinglyLinkedList<Data>::SinglyLinkedList(Data* first_element, Data* last_element) {
	for(; first_element != last_element; ++first_element)
		append(*first_element);
}



// Destructor
template<class Data>
SinglyLinkedList<Data>::~SinglyLinkedList() {
	erase();
}



// Get last node
template<class Data>
SinglyNode<Data>* SinglyLinkedList<Data>::last() {
	return this->_last;
}



// Append an element into the linked list
template<class Data>
void SinglyLinkedList<Data>::append(const Data &element) {
	SinglyNode<Data> *p = new SinglyNode<Data>(element);
	if (this->_last == NULL) {
		// if the linked list is empty
		this->_last = p;
		this->_size = 1;
		return;
	}
	// new last
	p->setNext(this->_last);
	this->_last = p;
	++this->_size;
}



// Remove the last node
template<class Data>
void SinglyLinkedList<Data>::removeLast() {
	if (this->_last == NULL)
		return;
	SinglyNode<Data>* p = this->_last->getNext();
	delete this->_last;
	this->_last = p;
	--this->_size;
}



// Empty linked list
template<class Data>
void SinglyLinkedList<Data>::clear() {
	for (SinglyNode<Data>* p = this->_last, *q = NULL; p != NULL; p = q) {
		q = p->getNext();
		delete p;
	}
	this->_last = NULL;
	this->_size = 0;
}



// Get size of list
template<class Data>
int SinglyLinkedList<Data>::size() {
	return this->_size;
}


#endif