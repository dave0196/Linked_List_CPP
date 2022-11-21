#include "global.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;


int main()
{
    // create nodes
    Node<string> *node1 = new Node<string>("Norway");
    Node<string> *node2 = new Node<string>("Tokyo");
    Node<string> *node3 = new Node<string>("Madrid");

    
    // create linked list
    LinkedList<string> linked_list{};
    cout << endl;
    
    // add nodes
    linked_list.addNode(node1);
    linked_list.addNode(node2);

    // linked_list.addNode(node2);
    // linked_list.addNode(node3);
    linked_list.displayNodes();
        // check if the list is empty
    cout << "is the list empty? " << linked_list.isEmpty();
    cout << endl;
    // get list size
    cout << "current list size is: " << linked_list.getSize() << endl;
    linked_list.removeNode(node1);
    cout << endl;
    // check if the list is empty
    cout << "is the list empty? " << linked_list.isEmpty();
    cout << endl;
    // get list size
    cout << "current list size is: " << linked_list.getSize() << endl;
    linked_list.displayNodes();
    
    return 0;
}
