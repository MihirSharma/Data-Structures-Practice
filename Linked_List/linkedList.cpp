#include<iostream>
#include "Header.h"

using namespace std;



template<typename T>
void linkedList<T>::createNode(T data) {
    if (size == 0) {
        listElement<T>* x = new listElement<T>;
        head = x;
        head->data = NULL;
        head->ptrbkd = nullptr;
        head->ptrfwd = x;
        tail = x;
        x->ptrbkd = nullptr;
        x->ptrfwd = nullptr;
        x->data = data;
    }
    if (size > 0) {
        listElement<T>* current, next;
        listElement<T>* x = new listElement<T>;
        current = tail;
        if (current->ptrfwd == nullptr) {
            x->ptrbkd = current;
            current->ptrfwd = x;
            x->data = data;
            x->ptrfwd = nullptr;
            tail = x;
            cout << "";
        }
    }
        size++;
}

template <typename T>
void linkedList<T>::insertAtPosition(T data,int idx) {
    if (size == 0 && idx == 0) {
        listElement<T>* x = new listElement<T>;
        head = x;
        x->ptrbkd = nullptr;
        x->ptrfwd = nullptr;
        x->data = data;
    }
    if (size > 0 && idx == 0) {
        listElement<T>* current, *next;
        listElement<T>* x = new listElement<T>;
        next = head;
        x->ptrbkd = nullptr;
        head = x;
        x->data = data;
        x->ptrfwd = next;
        next->ptrbkd = x;
    }
    if (size > 0) {
        listElement<T>* current, *next;
        current = goToIdx(idx-1);
        listElement<T>* x = new listElement<T>;
        if (current->ptrfwd == nullptr) {
            x->ptrbkd = current;
            current->ptrfwd = x;
            x->data = data;
            x->ptrfwd = nullptr;
        }
        else {
            x->ptrbkd = current;
            next = current->ptrfwd;
            current->ptrfwd = x;
            x->data = data;
            x->ptrfwd = next;
            next->ptrbkd = x;
        }

    }
    size++;

}

template<typename T>
T linkedList<T>::getValueAt(int idx) {
    listElement<T>* x;
    x = goToIdx(idx);
    return(x->data);


}

template <typename T>
listElement<T>* linkedList<T>::goToIdx(int idx) {
    listElement<T>* current;
    if (idx < size / 2) {
        current = head;
        for (int i = idx; i > 0; i--) {
            current = current->ptrfwd;
        }
        return current;
    }
    else {
        current = tail;
        for (int i = size - idx - 1; i > 0; i--) {
            current = current->ptrbkd;
        }
        return current;
    }
}

template <typename T>
int linkedList<T>::searchList(T data, int idx) {
    listElement<T>* current;
    current = goToIdx(idx);
    for (int i = size-idx; i > 0; i--) {
        if (data == current->data) {
            return size - i;
        }
        current = current->ptrfwd;
    }
    return -1;
}


template <typename T>
void linkedList<T>::deleteAtPosition(int idx) {
    listElement<T>* x = goToIdx(idx);
    listElement<T>* next, *prev;
    next = x->ptrfwd;;
    prev = x->ptrbkd;
    if (next == nullptr) {
        //next->ptrbkd = prev;
        prev->ptrfwd = nullptr;
        tail = prev;
    }
    else if (prev == nullptr){
        next->ptrbkd = nullptr;
        head = next;
        //prev->ptrfwd = next;
    }
    else {
        next->ptrbkd = prev;
        prev->ptrfwd = next;
    }
    delete(x);
    size--;
}



int main() {

    linkedList<int> x;
    x.createNode(1);
    x.createNode(2);
    x.createNode(5);
    x.createNode(9);
    x.createNode(2);
    x.createNode(1);
    for (int i = 0; i < x.size; i++) {
        cout << x.getValueAt(i) << endl;
    }
    cout << endl << endl;

    cout<<x.searchList(4,2)<<endl<<endl;


    for (int i = 0; i < x.size; i++) {
        cout << x.getValueAt(i) << endl;
    }

}
