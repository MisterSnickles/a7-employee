#pragma once

template <typename T>
class List;

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(T d) : data(d), next(nullptr) {}
    Node();
    ~Node() = default;

    template <typename U>
    friend class List;
};