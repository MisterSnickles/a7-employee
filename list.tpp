#pragma once
#include "list.h"
#include "employee.h"
#include <iostream>

template <typename T>
List<T>::List() : head(nullptr) {
    std::cout << "List constructor called this " << this << std::endl;
}

template <typename T>
List<T>::~List() {
    std::cout << "List destructor called this " << this << std::endl;
    while (head != nullptr) {
        pop();
    }
}

template <typename T>
int List<T>::getSize() const {
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
void List<T>::insert(T data, int pos) {
    int size = getSize();
    if (pos < 0 || pos > size) {
        std::cout << "Invalid position to insert data!" << std::endl;
        return;
    }


    Node<T>* newNode = new Node(data);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

template <typename T>
void List<T>::pop() {
    if (head == nullptr) {
        std::cout << "Error. List is empty." << std::endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void List<T>::remove(int pos) {
    if (head == nullptr || pos < 0 || pos >= getSize()) {
        std::cout << "Invalid position, or list empty." << std::endl;
        return;
    }

    // create temp node : assign head to next node : delete temp
    Node<T>* temp;

    if (pos == 0) {
        temp = head;
        head = head->next;
        delete temp;
        return;
    }
   
    Node<T>* current = head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    delete temp;
}

template <typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        current->data.printEmployee();  // Call print function of Employee
        current = current->next;
    }
}