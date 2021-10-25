#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <iostream>
using namespace std;

template <class T>
class myQueue {
public:
	myQueue(int maxSz);
	~myQueue();
	void enqueue(T item);
	T dequeue();
    int currentSize();
    bool isEmpty();
    bool isFull();

private:
	T *contents; /*Dynamic initiate (C++ keyword new) the holder array*/
	int front,rear;  /*Index in the array of the front and rear element*/
	int arrayLength;  /*The length of the contents holder array*/
		/* Keep in mind that the Queue will only hold up to (arrayLength - 1) elements*/
};

template <class T>
myQueue<T>::myQueue(int maxSz) {
	contents = new T[maxSz + 1];
	arrayLength = maxSz + 1;
	front = -1;
	rear = -1;
}

template <class T>
myQueue<T>::~myQueue() {
	delete [] contents;
}

template <class T>
void myQueue<T>::enqueue(T item) {
	if (isFull()) {
		cout << "Cannot enqueue. The queue is full.\n";
	} else if (front == -1) { // insert first element
		front = 0;
		rear = 1;
		contents[rear] = item;
	} else {
		rear = (rear + 1) % arrayLength;
		contents[rear] = item;
	}
}

template <class T>
T myQueue<T>::dequeue() {
	T frontVal;
	frontVal = contents[rear];
	front = (front + 1) % arrayLength;

	return frontVal;
}

template <class T>
int myQueue<T>::currentSize() {
	int curSize = (rear - front + arrayLength) % arrayLength;
	return curSize;
}

template <class T>
bool myQueue<T>::isEmpty() {
	bool status;

	if (currentSize() == 0) {
		status = true;
	} else {
		status = false;
	}

	return status;
}

template <class T>
bool myQueue<T>::isFull() {
	bool status;

	if (currentSize() == arrayLength - 1) { 
		status = true;
	} else {
		status = false;
	}

	return status;
}

#endif