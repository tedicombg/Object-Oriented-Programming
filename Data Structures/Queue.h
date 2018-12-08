#pragma once

#include <iostream>
#include "cassert"

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& _data, Node<T>* _next)
    {
        this -> data = _data;
        this -> next = _next;
    }
};

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const Queue& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.getSize(); i++)
        {
            this -> push(temp -> data);
            temp = temp -> next;
        }
    }

    void erase()
    {
        while(!isEmpty())
        {
            this -> pop();
        }
    }
public:
    Queue()
    {
        this -> first = nullptr;
        this -> last = nullptr;
        this -> size = 0;
    }

   Queue(const Queue& other)
   {
       this -> copy(other);
   }

   Queue& operator= (const Queue& other)
   {
       if(this != other)
       {
           this -> erase();
           this -> copy(other);
       }
       return *this;
   }
   const T& front() const
   {
       assert(first != nullptr);

       return this -> first -> data;
   }
   const T& back() const
   {
       assert(last != nullptr);

       return this -> last -> data;
   }
   void push(const T& data)
   {
       Node<T>* newNode = new Node<T>(data);
       if (isEmpty())
       {
           this -> first = newNode;
           this -> last = newNode;
       }
       else
       {
           this -> last -> next = newNode;
           this -> last = newNode;
       }
       this -> size ++;
   }
   void pop()
   {
       if(!isEmpty())
       {
           Node<T>* temp = first;
           this -> first = this -> first -> next;
           delete temp;
           this -> size --;
       }
   }

   bool isEmpty() const
   {
       return this -> size == 0;
   }
   size_t getSize() const
   {
       return this -> size;
   }

   ~Queue()
   {
       this -> erase();
   }

};
