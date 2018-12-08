#pragma once

template <class T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node (const T&, Node*, Node*);
};

template <typename T>
class Dllist
{
private:
    Node<T>* first;
    size_t currSize;
    Node<T>* lastFound;
    size_t lastFoundIndex;

    void copy(const Dllist<T> &other);
    void erase();
public:
    Dllist();
    Dllist(const Dllist<T> &other);
    Dllist& operator= (const Dllist<T> &other);

    T& operator[] (size_t index);

    void push(const T&);
    T& top();
    void pop();

    size_t size();

    ~Dllist();
};
