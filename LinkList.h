#pragma once

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& data, Node<T>* next)
    {
        this -> data = data;
        this -> next = next;
    }
};

template <typename T>
class List
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const List& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.size; i++)
        {
            push_back(temp -> data);
            temp = temp -> next;
        }
    }
    void destroy()
    {
        while (size > 0)
        {
            this -> pop_front;
        }
    }
public:
    List()
    {
        this -> first = NULL;
        this -> last  = NULL;
        this -> size  = 0;
    }
    List(const List& other)
    {
        this -> copy(other);
    }
    List& operator =(const List& other)
    {
        if(this != other)
        {
            this -> destroy();
            copy(other);
        }
    return *this;
    }
    ~List()
    {
        this -> destroy();
    }
    void pop_front()
    {
        Node<T>* temp = first;
        first = first -> next;
        delete temp;
        size--;
    }
    void pop_back()
    {
        Node<T>* temp = last;
        Node<T>* start = first;
        while(start -> next != last)
        {
            start = start -> next;
        }
        last = start;
        delete temp;
        size--;
    }
    void push_back(T data)
    {
        Node<T>* temp = new Node<T>(data, NULL);
        if(temp)
        {
            if(size == 0)
            {
                this -> first = temp;
                this -> last  = temp;
            }
            else
            {
                this -> last -> next = temp;
                this -> last = temp;
            }
            size++;
        }
    }
    void push_front(T data)
    {
        Node<T>* temp = new Node<T>(data, first);
        this -> first = temp;
    }
    void push(T data, int index)
    {
        Node<T>* temp2 = first;
        Node<T>* temp = new Node<T>(data, NULL);
        while(index != 0)
        {
            temp2 = temp2->next;
            index--;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
    T get (int index)
    {
        Node<T>* temp = first;
        for(size_t i = 0; i < index; i++)
        {
            temp = temp -> next;
        }
        return temp -> data;
    }
};
