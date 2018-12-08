#pragma once

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node<T>(const T& _data, Node<T>* _next)
    {
        this -> data = _data;
        this -> next = _next;
    }
};


template <typename T>
class Stack
{
private:
    Node<T>* topElement;
    size_t size;

    void copy(const Stack<T>& other)
    {
        if(other.topElement == nullptr)
        {
            this -> topElement == nullptr;
            this -> size = 0;
            return;
        }
        this -> topElement = new Node<T>(other.topElement -> data, other.topElement -> next);

        Node<T>* temp1 = this -> topElement;
        Node<T>* temp2 = other.topElement;

        while(temp2 != nullptr)
        {
            temp1 -> next = new Node<T>(temp2 -> next -> data, temp2 -> next -> next);
            temp2 = temp2 -> next;
            temp1 = temp1 -> next;
        }
        this -> size = other.size;
    }

    void print() const
    {
        Node<T>* temp = topElement;

        while(temp != nullptr)
        {
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    }

    void reserseCopy(const Stack<T>& other)
    {
        Node<T>* temp = other.topElement;

        while(temp != nullptr)
        {
            this -> push(temp -> data);
            temp = temp -> next;
        }
    }

    void erase()
    {
        while(!this -> isEmpty())
        {
            this -> pop();
        }
    }

public:
    Stack()
    {
        this -> topElement = nullptr;
        this -> size = 0;
    }
    Stack(const Stack<T>& other)
    {
        this -> copy(other);
    }
    Stack& operator = (const Stack<T> other)
    {
        if(this != other)
        {
            this -> erase();
            this -> copy();
        }
        return *this;
    }
    ~Stack()
    {
        this -> erase();
    }



    void push(const T& element)
    {
        Node<T>* addElement = new Node<T>(element, this -> topElement);
        if(this -> isEmpty())
        {
            this -> topElement = addElement;
        }
        else
        {
            addElement -> next = this -> topElement;
            this -> topElement = addElement;
        }
        this -> size++;
    }

    void pop()
    {
        if(!this -> isEmpty())
        {
            Node<T>* temp = this -> topElement;
            this -> topElement = this -> topElement -> next;
            delete temp;
            size--;
        }
    }

    const T& top() const
    {
        if(!this -> isEmpty())
        {
            return this -> topElement -> data;
        }
        throw "Empty stack";
    }

    bool isEmpty() const
    {
        return this -> size == 0;
    }

    size_t getSize() const
    {
        return this -> size;
    }
};


