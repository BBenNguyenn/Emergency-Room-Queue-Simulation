// CLASS: Node
// REMARKS: What is the purpose of this class?
//	To represent the node for our linked list queues.
//-----------------------------------------
#include <iostream>
#include "Node.hpp"
#include "ListItem.hpp"
//Need to include ListItem.h because we call one of its methods
// (theItem's print()!)
using namespace std;
Node::Node(ListItem *initItem, Node *initLink) : item(initItem), link(initLink) {}
Node::~Node() {}

void Node::print()
{
  getItem()->print();
  if (link != NULL)
    getLink()->print();
}

ListItem *Node::getItem() { return item; }
Node *Node::getLink() { return link; }
void Node::setLink(Node *newLink) { link = newLink; }
