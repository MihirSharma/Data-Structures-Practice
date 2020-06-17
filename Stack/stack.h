#pragma once

template<typename T>
class stack {

private:
	int currentSize;
	T* arr;
	int top;

public:
	stack(int size);
	~stack();
	void push(T data);
	T pop();
	T peek();
	int size();

};
