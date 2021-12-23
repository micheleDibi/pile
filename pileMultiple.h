#ifndef PILEMULTIPLE_H
#define PILEMULTIPLE_H

#include "pilePuntatori.h"

template <class T>
class multipleStack{
public:
    typedef typename linkedStack<T>::valueType object;

    multipleStack();
    multipleStack(unsigned int);
    void push (object&, unsigned int);
    void pop (unsigned int);

private:
    linkedStack<T> *elements;
    int lenght;
};

template <class T>
multipleStack<T>::multipleStack() {
    elements = new linkedStack<T>[10];
    lenght = 0;
}

template <class T>
multipleStack<T>::multipleStack(unsigned int dim) {
    elements = new linkedStack<T>[dim];
    lenght = 0;
}

template <class T>
void multipleStack<T>::push (object &elem, unsigned int pos) {
    if(pos < lenght) {
        elements[pos].push(elem);
    }
}

template <class T>
void multipleStack<T>::pop (unsigned int pos) {
    if(pos < lenght) {
        elements[pop].pop();
    }
}


#endif // PILEMULTIPLE_H
