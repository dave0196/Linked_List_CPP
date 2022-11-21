#include "Node.h"
#include "global.h"
#include <memory>
#include <iostream>
#pragma once

// class declaration

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList();
    int addNode(Node<T> *newnode);
    int removeNode(Node<T> *toBeRemoved);
    int displayNodes();
    bool isEmpty();
    int getSize();
};

// function implementation
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
int LinkedList<T>::addNode(Node<T> *newnode)
{
    if (head == nullptr && tail == nullptr) // first time adding a node
    {
        head = newnode;
        tail = newnode;
        newnode->next = nullptr;
        size++;
        return 0;
    }
    else // there are nodes present, update head and tail
    {
        newnode->next = head; // new guy points to head
        head = tail;            // old head now points to tail
        tail->next = nullptr; // tail points to nothing
        head = newnode;         // new node becomes head
        size++;                 // increase size
        return 0;
    }
    return -1; // there was an error and the node was not added, return error code
}

template <typename T>
int LinkedList<T>::removeNode(Node<T> *toBeRemoved)
{
    Node<T> *runner;  
    runner = head;
    while (runner != nullptr)
    {
        if (runner == toBeRemoved)
        {
            if (head == nullptr && tail == nullptr) // first check if the list is empty
            {
                return -1; // list must be empty
            }
            else if (toBeRemoved->next == nullptr) // list has only one node
            {
                toBeRemoved->next = nullptr;
                toBeRemoved = nullptr;
                head = tail = nullptr;
                size--;
                return 0;
            }
            else if (runner == head)
            {
                head = toBeRemoved->next; // pass head pointer to next node
                toBeRemoved->next = nullptr; 
                size--;
                return 0;
            }
            else if (runner == tail)
            {
                toBeRemoved = nullptr;
                size--;
                return 0;
            }
            else // node to be deleted must be somewhere in the middle, need to find it
            {
                toBeRemoved->next = nullptr;
                size--;
                return 0;
            }
        }
        runner = runner->next;
    }
    delete runner;
    return -1;
};

template <typename T>
int LinkedList<T>::displayNodes()
{
    if (head == nullptr && tail == nullptr)
        return -1;
    else
    {
        Node<T> *runner = head;
        while (runner != nullptr)
        {
            std::cout << runner->data << std::endl;
            runner = runner->next;
        }
        delete runner;
        return 0;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return (size == 0 ? true : false);
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size;
}
