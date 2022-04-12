#include "global.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;


int main()
{
    // create nodes
    Node<int> *node1 = new Node<int>(10);
    Node<int> *node3 = new Node<int>(27);
    Node<int> *node2 = new Node<int>(1);

    
    // create linked list
    LinkedList<int> linked_list{};
    cout << endl;
    
    // add nodes
    linked_list.addNode(node1);
    linked_list.addNode(node2);
    linked_list.addNode(node3);
    linked_list.displayNodes();
    cout << endl;
    // check if the list is empty
    cout << "is the list empty? " << linked_list.isEmpty();
    cout << endl;
    // get list size
    cout << "current list size is: " << linked_list.getSize() << endl;
    
    return 0;
}
