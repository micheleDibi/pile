#ifndef PILE_H
#define PILE_H

template <class T>
class linearStack {
public:
    typedef T valueType;

    virtual void createStack() = 0;
    virtual bool isEmpty() const = 0;
    virtual valueType top() const = 0;
    virtual void pop() = 0;
    virtual void push(valueType) = 0;

};

#endif
