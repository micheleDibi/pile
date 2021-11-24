#ifndef PILEVETTORI_H
#define PILEVETTORI_H

#include "pile.h"

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
    for(int i = 0; i < lenght; i++) {
        elements[i+1] = elements[i];
    }

    elements[0] = elem;
}

#endif // PILEVETTORI_H
