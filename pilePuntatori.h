#ifndef PILEPUNTATORI_H
#define PILEPUNTATORI_H

#include <iostream>
#include "pile.h"

using namespace std;

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

    void print();

    void pushWithoutDuplicate(valueType);
    int calcolaProfondita(valueType);
    valueType prendiDaProfondita(int);

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
void linkedStack<T>::createStack() {}

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
    lenght--;
}

template <class T>
void linkedStack<T>::push(linkedStack<T>::valueType elem) {
    node<T>* supp = new node<T>;
    supp->nvalue = elem;

    supp->next = head;
    head = supp;

    lenght++;
}

template <class T>
void linkedStack<T>::pushWithoutDuplicate(linkedStack<T>::valueType elem) {
    node<T>* temp;
    bool check = false;
    temp = head;

    for(int i = 0; i < lenght; i++) {
        if(temp->nvalue == elem) {
            check = true;
        }

        temp = temp->next;
    }

    if(!check) {
        push(elem);
    }
}

template <class T>
int linkedStack<T>::calcolaProfondita(linkedStack<T>::valueType elem) {
    node<T>* temp;
    bool check = false;
    temp = head;
    int prof = 0;

    int i = 0;
    while(check == false && i < lenght) {

        if(temp->nvalue == elem) {
            check = true;
        }

        temp = temp->next;
        i++;
    }

    if(check == false) {
        prof = -1;
    }

    return prof;
}

template <class T>
typename linkedStack<T>::valueType linkedStack<T>::prendiDaProfondita(int prof) {
    valueType val;
    node<T>* temp;
    temp = head;

    if(prof < lenght) {
        int i = 0;
        while(i <= prof) {
            temp = temp->next;
        }
        val = temp->nvalue;
    }

    return val;
}

template <class T>
void linkedStack<T>::print() {
    node<T>* pos = head;

    cout << "[";
    for(int i = 0; i < lenght; i++) {
        cout << pos->nvalue << ", ";
        pos = pos->next;

    }

    cout << "]";
}

#endif // PILEPUNTATORI_H
