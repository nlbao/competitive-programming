/*
	Student Name: Nguyễn Lê Bảo
	Student ID: 1351051
	Email: nlbao@apcs.vn
	Course: CS162
	Program # : Week 6 - Problem 03
	Date: 14/03/2014
	File: Stack.cpp
*/

#ifdef _RSStack_


// Constructor with no arguments
template<class Data>
Stack<Data>::Stack() {
	this->_top = NULL;
	this->_size = 0;
}



// Constructor with one node
template<class Data>
Stack<Data>::Stack(SinglyNode<Data>* node) {
	this->_top = node;
	this->_size = 1;
}



// Constructor with one data element
template<class Data>
Stack<Data>::Stack(const Data &element) {
	this->_top = new SinglyNode<Data>(element);
	this->_size = 1;
}



// Constructor with an array of elements
template<class Data>
Stack<Data>::Stack(Data* first_element, Data* last_element) {
	for(; first_element != last_element; ++first_element)
		push(*first_element);
}



// Push	a node on top of stack
template<class Data>
void Stack<Data>::push(const Data &element) {
	SinglyNode<Data>* p = new SinglyNode<Data>(element);
	p->setNext(this->_top);	// set pNext of new node = current top
	this->_top = p;			// set top = new node
	++this->_size;			// increase size of stack
}



// Pop the top node
template<class Data>
const Data& Stack<Data>::pop() {
	if (this->_top == NULL)
		return NULL;
	SinglyNode<Data>* p = this->_top->getNext();	// save next node of top
	Data result = this->_top->getData();	// save data of top
	// remove current top and set new top
	delete this->_top;
	this->_top = p;
	--this->_size;
	return result;	// return old top's data
}



// Get the top node (but doesn't remove it)
template<class Data>
const Data& Stack<Data>::top() const {
	if (this->_top == NULL)
		return NULL;
	return this->_top->getData();
}



// Empty linked list
template<class Data>
void Stack<Data>::clear() {
	for (SinglyNode<Data>* p = this->_top, *q; p != NULL; p = q) {
		q = p->getNext();
		delete p;
	}
	this->_top = NULL;
	this->_size = 0;
}



// Get size of list
template<class Data>
int Stack<Data>::size() const {
	return this->_size;
}



// Chec if stack is empty
template<class Data>
bool Stack<Data>::is_empty() const {
	return this->_size == 0;
}


#endif