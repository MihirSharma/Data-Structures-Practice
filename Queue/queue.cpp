#include<iostream>
#include "queue.h"

using namespace std;

template<typename T>
queue<T>::queue(int size) {
	arr = (T*)malloc(size * sizeof(T));
	currentSize = 0;
	maxSize = size;
	head = 0;
	tail = -1;
}

template<typename T>
queue<T>::~queue() {
	free(arr);
}

template<typename T>
void queue<T>::enqueue(T data) {

	tail++;
	arr[tail] = data;
	currentSize++;

}

template<typename T>
T queue<T>::dequeue() {
	T x = arr[head];
	head++;
	currentSize--;
	return x;
}

template<typename T>
bool queue<T>::isEmpty() {
	if (head > tail) {
		head = 0;
		tail = -1;
		return true;
	}
	else return false;
}

template<typename T>
bool queue<T>::isFull() {
	if (currentSize == maxSize) return true;
	else return false;
}

template<typename T>
int queue<T>::size() {
	return currentSize;
}

template<typename T>
T queue<T>::front() {

	return arr[head];

}


int main() {


	queue<int> x(10);

	cout << "is Empty : " << x.isEmpty() << endl;

	for (int i = 0; i < 7; i++) {
		x.enqueue(i);
		cout << "is Empty : " << x.isEmpty() << "\t" << "is Full : " << x.isFull() <<endl;
	}

	for (int i = 0; i < 10; i++) {
		if (x.isEmpty()) {
			cout << "breaking loop : queue is empty";
			break;
		}
		cout << x.dequeue() << "\t" << "is Empty : ";
		cout<< x.isEmpty()<<"\t"<<"head : " << x.head<<"\t"<<"tail = "<<x.tail<<endl;
	}
	cout << "head : " << x.head << "\t" << "tail :  " << x.tail;



}
