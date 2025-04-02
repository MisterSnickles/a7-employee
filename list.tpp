#pragma once
#include "list.h"
#include "employee.h"
#include <iostream>

template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
    while (head != nullptr) {
        pop();
    }
}

template <typename T>
void List<T>::push(T data) {
    Node<T>* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::pop() {
    if (head == nullptr) {
        std::cout << "List empty." << std::endl;
        return;
    }

    // create temp node : assign head to next node : delete temp
    Node<T>* temp = head;
    head = head->next;
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