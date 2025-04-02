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
    void insert(T, int);
    void remove(int);
    int getSize() const; // gets list size
    bool isEmpty() const;
    void print();
};

#include "list.tpp"