

#include "Node.hpp"

Node::Node(int item, Node *next) {
    this->item = item;
    this->next = next;
}
Node::Node(int item) {
    this->item = item;
    this->next = 0;
}
