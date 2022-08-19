

/* 
 * File:   Avl.hpp
 * Author: HAKAN KIRIK
 *
 * Created on August 19, 2022, 3:02 PM
 */

#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include <cmath>
#include "NodeAVL.hpp"
#include "Queue.hpp"
using namespace std;

class AVL {
private:
    NodeAVL *root;
    NodeAVL* SearchAndAdd(NodeAVL *subNode, int item, Queue *items);
    NodeAVL* SwapWithLeftChild(NodeAVL *subNode);
    NodeAVL* SwapWithRightChild(NodeAVL *subNode);
    bool DeleteNode(NodeAVL *&subNode);
    void postorderMaxDel(NodeAVL *subNode);
    void postorderDel(NodeAVL *subNode);
    void preorder(NodeAVL *subNode);
    int Height(NodeAVL *subNode);

public:
    AVL();
    bool isEmpty()const;
    void Add(Queue* item);
    void preorder();
    int Height();
    void Clear();
    ~AVL();
};


#endif /* AVL_HPP */

