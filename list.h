#pragma once

#include "node.h"

template <typename T>

class List {
private:
    Node<T>* head;

public:

    // constructor : destructor
    List();
    ~List();

    // member functions
    void push(T);
    void pop();
    bool isEmpty() const;
    void print();
};

#include "list.tpp"