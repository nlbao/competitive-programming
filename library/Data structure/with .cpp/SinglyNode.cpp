#ifdef _RSSinglyNode_


// Constructor with no arguments
template<class Data>
SinglyNode<Data>::SinglyNode() {
	this->pNext = NULL;
}



// Constructor with data
template<class Data>
SinglyNode<Data>::SinglyNode(const Data &data) {
	this->data = data;
	this->pNext = NULL;
}



// Copy constructor
template<class Data>
SinglyNode<Data>::SinglyNode(const SinglyNode<Data> &other) {
	this->data = other.data;
	this->pNext = other.pNext;
}



// Destructor
template<class Data>
SinglyNode<Data>::~SinglyNode() {
	this->data.Data::~Data();
}



// Set data of node
template<class Data>
void SinglyNode<Data>::setData(const Data &data) {
	this->data = data;
}



// Get data of node
template<class Data>
const Data& SinglyNode<Data>::getData() const {
	return this->data;
}



// Set the next node to the new node with data
template<class Data>
void SinglyNode<Data>::setNext(const Data &data) {
	this->pNext = new SinglyNode<Data>(data);
}



// Set the next node to an exist node
template<class Data>
void SinglyNode<Data>::setNext(SinglyNode<Data>* &other) {
	this->pNext = other;
}



// Get the next node
template<class Data>
SinglyNode<Data>*& SinglyNode<Data>::getNext() {
	return this->pNext;
}



// Check if left node < right node
template<class Data>
bool SinglyNode<Data>::operator < (const SinglyNode<Data> &other) const {
	return this->data < other.data;
}



// Check if left node == right node
template<class Data>
bool SinglyNode<Data>::operator == (const SinglyNode<Data> &other) const {
	return this->data == other.data;
}



// Check if left node > right node
template<class Data>
bool SinglyNode<Data>::operator > (const SinglyNode<Data> &other) const {
	return this->data > other.data;
}


#endif