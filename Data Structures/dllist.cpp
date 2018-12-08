#include "dllist.h"
#include <cassert>
#include <iostream>

template <typename T>
Node<T>::Node(const T& _data, Node* _next, Node* _previous )
{
    this -> data     = _data;
    this -> next     = _next;
    this -> previous = _previous;
}


template <typename T>
Dllist<T>::Dllist()
{
    first = nullptr;
    currSize = 0;
    lastFoundIndex = -1;
    lastFound = nullptr;
}
template <typename T>
Dllist<T>::Dllist(const Dllist<T> &other)
{
    copy(other);
}
template <typename T>
void Dllist<T>::copy(const Dllist<T> &other)
{
    if(other.first == nullptr)
    {
        first = nullptr;
        return;
    }
    first = new Node<T> (other.first -> data, nullptr, nullptr);
    Node<T>* lastCreated = first;
    Node<T>* nextToCopy  = other.first -> next;

    while(nextToCopy != nullptr)
    {
        lastCreated -> next = new Node<T> (nextToCopy -> data, nullptr, lastCreated);
        lastCreated = lastCreated -> next;
        nextToCopy  = nextToCopy  -> next;
    }

    currSize = other.currSize;

    /*Restart Iteration*/
    lastFoundIndex = -1;
    lastFound = nullptr;
}


template <typename T>
void Dllist<T>::erase()
{
    Node<T>* next;
    while(first != nullptr)
    {
        next = first -> next;
        delete first;
        first = next;
    }
    currSize = 0;
}

template <typename T>
Dllist<T>& Dllist<T>::operator= (const Dllist<T> &other)
{
    if(this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
T& Dllist<T>::operator[] (size_t index)
{
    assert (first != nullptr);

    if(lastFoundIndex != -1 && lastFoundIndex == index - 1)
    {
        assert(lastFound != nullptr);
        lastFound = lastFound -> next;
    }
    else if (lastFoundIndex != -1 && lastFoundIndex == index + 1)
    {
        assert(lastFound != nullptr);
        lastFound = lastFound -> previous;
    }
    else
    {
        lastFound = first;
        while(lastFound != nullptr && index > 0)
        {
            lastFound = lastFound -> next;
            index --;
        }
    }
}

template <typename T>
void Dllist<T>::push(const T &data)
{
//first сочи нещо

    first = new Node<T> (data, first, nullptr);
    if(first -> next != nullptr)
    {
        first -> next -> previous = first;
    }
    currSize ++;

    /*Restart Iteration*/
    lastFoundIndex = -1;
    lastFound = nullptr;
}

template <typename T>
T& Dllist<T>::top()
{
    assert(first != nullptr);

    return first -> data;
}

template <typename T>
void Dllist<T>::pop()
{
    assert(first != nullptr);
    Node<T>* next = first -> next;
    delete first;
    first = next;
    currSize --;

    /*Restart Iteration*/
    lastFoundIndex = -1;
    lastFound = nullptr;
}

template <typename T>
size_t Dllist<T>::size()
{
    return currSize;
}

template <typename T>
Dllist<T>::~Dllist()
{
    erase();
}





