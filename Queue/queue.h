#pragma once

template<typename T>
class queue {

private:
	int maxSize, currentSize;
	T* arr;
public:
	int head, tail;
	queue(int size);
	void enqueue(T data);
	T dequeue();
	bool isEmpty();
	bool isFull();
	int size();
	T front();
	~queue();

};
