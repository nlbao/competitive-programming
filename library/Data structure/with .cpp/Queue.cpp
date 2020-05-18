#ifdef _RSQueue_


// Constructor with no arguments
template<class Data>
Queue<Data>::Queue() {
	this->_front = this->_rear = NULL;
	this->_size = 0;
}



// Constructor with one node
template<class Data>
Queue<Data>::Queue(SinglyNode<Data>* node) {
	this->_front = this->_rear = node;
	this->_size = 1;
}



// Constructor with one data element
template<class Data>
Queue<Data>::Queue(const Data &element) {
	this->_front = this->_rear = new SinglyNode<Data>(element);
	this->_size = 1;
}



// Constructor with an array of elements
template<class Data>
Queue<Data>::Queue(Data* first_element, Data* last_element) {
	for(; first_element != last_element; ++first_element)
		enqueue(*first_element);
}



// Push	a node at the end of queue	
template<class Data>
void Queue<Data>::enqueue(const Data &element) {
	SinglyNode<Data>* p = new SinglyNode<Data>(element);
	if (this->_front == NULL) {
		// if the queue is empty
		this->_front = this->_rear = p;
		this->_size = 1;
		return;
	}
	this->_rear->setNext(p);	// set pNext of rear = new node
	this->_rear = p;			// set rear = new node
	++this->_size;	// increase size of queue
}



// Pop the first node of queue
template<class Data>
const Data& Queue<Data>::dequeue() {
	if (this->_front == NULL)
		return NULL;
	SinglyNode<Data>* p = this->_front->getNext();	// save the next node of front node
	Data result = this->_front->getData();			// save data of front node
	delete this->_front;	// remove current front
	this->_front = p;		// set new front
	--this->_size;
	return result;	// return old front's data
}



// Get the first node (but doesn't remove it)
template<class Data>
const Data& Queue<Data>::front() const {
	if (this->_front == NULL)
		return NULL;
	return this->_front->getData();
}



// Empty linked list
template<class Data>
void Queue<Data>::clear() {
	for (SinglyNode<Data>* p = this->_front, *q; p != NULL; p = q) {
		q = p->getNext();
		delete p;
	}
	this->_front = this->_rear = NULL;
	this->_size = 0;
}



// Get size of list
template<class Data>
int Queue<Data>::size() const {
	return this->_size;
}



// Chec if queue is empty
template<class Data>
bool Queue<Data>::is_empty() const {
	return this->_size == 0;
}


#endif