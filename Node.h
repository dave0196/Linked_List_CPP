#pragma once

template<class> class LinkedList;

template <typename T>

class Node
{
private:
    T data;
    Node<T> *next = nullptr;

public:
    Node(T data) // constructor
    {
        this->data = data;
    }

    ~Node() {} // destructor

    T getData() // getter
    {
        return data;
    }

    // setter
    void setData(T newdata)
    {
        data = newdata;
    }

    Node<T> *getNext()
    {
        return next;
    }

    void setNext(Node<T> *newnext)
    {
        next = newnext;
    }
    
    friend class LinkedList<T>;
};