#pragma once
#include <cassert>
#include <cstdlib>
using namespace std;

template <typename T>
class Vector
{
private:
    T* elements;
    size_t size;
    size_t capacity;

    void copy(const Vector<T>& other)
    {
        this -> elements  = new T[this -> capacity];
        this -> size      = other.size;
        this -> capacity  = other.capacity;
    }
    void freeMemory()
    {
        delete[] elements;
    }
    void resize(size_t newCapacity)
    {
        assert(newCapacity >= this -> size);
        this -> capacity = newCapacity;
        T* temp = new T[this -> capacity];

        for(size_t i = 0; i < this -> size; ++i)
        {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    }
public:
    Vector(size_t _capacity = 1)
    {
        this -> capacity = _capacity;
        this -> elements = new T[this -> capacity];
        this -> size     = 0;
    }
   Vector(size_t _capacity, const T& initialValue)
   {
       this -> capacity = _capacity;
       this -> elements = new T[this -> capacity];
       this -> size     = 0;

       for(size_t i = 0; i < size; ++i)
       {
           this -> elements[i] = initialValue[i];
       }
   }
   Vector(const Vector<T>& other)
   {
       this -> copy(other);
   }
   Vector<T> operator = (const Vector<T>& other)
   {
       if(this != &other)
       {
           freeMemory();
           copy(other);
       }
       return *this;
   }
   ~Vector()
   {
       freeMemory();
   }


   T& operator[] (size_t index)
   {
       assert(index >=0 && index < this -> size);
       return this -> elements[index];
   }

   T operator[] (size_t index ) const
   {
       assert(index >= 0 && index < this -> size);
       return this -> elements[index];
   }

   void push_back(const T& elem)
   {
       if(this -> size <= this -> capacity)
       {
           resize(this -> capacity * 2);
       }
       this -> elements[this -> size] = elem;
       ++this -> size;
   }
   T pop_back()
   {
       assert(!empty());
       return this -> elements[--size];
   }
   bool empty()
   {
       return this -> size > 0;
   }
    size_t _size() const
    {
        return this -> size;
    }
    size_t _capacity() const
    {
        return this -> capacity();
    }
};

