#pragma once

template<typename T>
struct listElement {

public:
    listElement<T>* ptrfwd;
    listElement<T>* ptrbkd;
    T data;
};

template <typename T>
class linkedList {


public:
    listElement<T>* head = NULL;
    listElement<T>* tail = NULL;
    int size = 0;
    listElement<T>* goToIdx(int idx);
    int searchList(T data, int idx = 0);
    void createNode(T data);
    void insertAtPosition(T data, int idx);
    T getValueAt(int idx);
    void deleteAtPosition(int idx);
};
