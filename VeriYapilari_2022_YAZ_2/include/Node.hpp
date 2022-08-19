
/* 
 * File:   Node.hpp
 * Author:HAKAN KIRIK
 *
 * Created on August 18, 2022, 11:09 PM
 */

#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    int item;
    Node *next;
    Node(int item);
    Node(int, Node*);
};


#endif /* NODE_HPP */

