#include "Node.h"
#include "global.h"
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
    void displayNodes();
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
        newnode->setNext(nullptr);
        size++;
        return 0;
    }
    else // there are nodes present, update head and tail
    {
        newnode->setNext(head); // new guy points to head
        head = tail;            // old head now points to tail
        tail->setNext(nullptr); // tail points to nothing
        head = newnode;         // new node becomes head
        size++;                 // increase size
        return 0;
    }
}

template <typename T>
int LinkedList<T>::removeNode(Node<T> *toBeRemoved)
{
    return 0;
};

template <typename T>
void LinkedList<T>::displayNodes()
{
    Node<T> *runner = head;
    while (runner != nullptr)
    {
        std::cout << runner->getData() << std::endl;
        runner = runner->getNext();
    }
    delete runner;
};

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return (head == nullptr && tail == nullptr);
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size;
}
