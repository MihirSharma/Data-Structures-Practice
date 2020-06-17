#include<iostream>
#include "stack.h"

using namespace std;

template<typename T>
stack<T>::stack(const int size ) {

	arr = (T*)malloc(size * sizeof(T));
	top = -1;
	currentSize = 0;
}

template<typename T>
stack<T>::~stack(){
	free(arr);
}

template<typename T>
void stack<T>::push(T data) {

	top++;
	currentSize++;
	arr[top] = data;

}

template<typename T>
T stack<T>::pop() {
	T x = arr[top];
	top--;
	currentSize--;
	return x;
}

template<typename T>
T stack<T>::peek() {
	return arr[top];
}

template<typename T>
int stack<T>::size() {
	return currentSize;
}


int main() {

	stack<int> x(10);

	for (int i = 0; i < 10; i++) {
		x.push(i);
	}

	cout <<"Top of the stack : "<< x.peek() << endl << endl;
	cout << " --------------------------------"<<endl;
	cout << "||" << "\t" << "Stack" << "\t" << "|" << "\t" << "Index" << "\t" << "||" << endl;
	cout << " --------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "||" << "\t" << x.pop() << "\t" << "|" << "\t" << x.size() << "\t" << "||" << endl;
		cout << " --------------------------------"<<endl;
	}

}
