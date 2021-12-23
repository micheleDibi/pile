#ifndef PILEVETTORI_H
#define PILEVETTORI_H

#include <iostream>
#include "pile.h"
using namespace std;

#define MAX 50

template <class T>
class vectorStack : public linearStack<T> {
public:
    typedef typename linearStack<T>::valueType valueType;

    vectorStack();
    vectorStack(int);
    ~vectorStack();

    void createStack();
    bool isEmpty() const;
    valueType top() const;
    void pop();
    void push(valueType);

    void pushWithoutDuplicate(valueType);

    void print();

private:
    valueType *elements;
    int dim;
    int lenght;
};

template <class T>
vectorStack<T>::vectorStack() {
    dim = MAX;
    this->createStack();
}

template <class T>
vectorStack<T>::vectorStack(int dimension) {
    dim = dimension;
    this->createStack();
}

template <class T>
vectorStack<T>::~vectorStack() {
    lenght = 0;
    delete[] elements;
}

template <class T>
void vectorStack<T>::createStack() {
    elements = new valueType[dim];
    lenght = 0;
}

template <class T>
bool vectorStack<T>::isEmpty() const{
    return lenght == 0;
}

template <class T>
typename vectorStack<T>::valueType vectorStack<T>::top() const{
    return elements[0];
}

template <class T>
void vectorStack<T>::pop(){
    if(!isEmpty()) {
        for(int i = 0; i < lenght-1; i++) {
            elements[i] = elements[i+1];
        }

        lenght--;
    }
}

template <class T>
void vectorStack<T>::push(vectorStack<T>::valueType elem) {

    for(int i = lenght; i != 0; i--) {
        elements[i] = elements[i-1];
    }

    elements[0] = elem;
    lenght++;
}

template <class T>
void vectorStack<T>::pushWithoutDuplicate(vectorStack<T>::valueType elem) {
    bool check = false;

    for(int i = 0; i < lenght; i++) {
        if(elements[i] == elem) {
            check = true;
        }
    }

    if(!check) {
        push(elem);
    }
}

template <class T>
void vectorStack<T>::print() {

    cout << "[";
    for(int i = 0; i < lenght; i++) {
        cout << elements[i] << ", ";
    }
    cout << "]";

    return;
}

#endif // PILEVETTORI_H
