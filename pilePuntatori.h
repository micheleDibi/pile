#ifndef PILEPUNTATORI_H
#define PILEPUNTATORI_H

#include "pile.h"

template <class T>
class linkedStack;

template <class T>
class node{
    friend class linkedStack<T>;

private:
    T nvalue;
    node* next;
};

template <class T>
class linkedStack : public linearStack<T> {
public:
    typedef typename linearStack<T>::valueType valueType;

    linkedStack();
    ~linkedStack();

    void createStack();
    bool isEmpty() const;
    valueType top() const;
    void pop();
    void push(valueType);

private:

    node<T>* head;
    int lenght;

};

template <class T>
linkedStack<T>::linkedStack() {
    head = new node<T>;
    head->next = head;

    lenght = 0;
}

template <class T>
linkedStack<T>::~linkedStack() {
    while(!isEmpty()) {
        node<T>* supp = head;
        head = head->next;
        delete supp;
    }
}

template <class T>
void linkedStack<T>::createStack() {

}

template <class T>
bool linkedStack<T>::isEmpty() const {
    if(head->next == head) {
        return true;
    } else return false;
}

template <class T>
typename linkedStack<T>::valueType linkedStack<T>::top() const{
    if(!isEmpty()) {
        return head->nvalue;
    }
}

template <class T>
void linkedStack<T>::pop() {
    node<T>* supp = head;
    head = head->next;
    delete supp;
}

template <class T>
void linkedStack<T>::push(linkedStack<T>::valueType elem) {
    node<T>* supp = new node<T>;
    supp->nvalue = elem;

    supp->next = head;
    head = supp;
}

#endif // PILEPUNTATORI_H
