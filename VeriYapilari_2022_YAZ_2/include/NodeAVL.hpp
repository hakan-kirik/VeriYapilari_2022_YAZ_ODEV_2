

/* 
 * File:   NodeAVL.hpp
 * Author: HAKAN KIRIK
 *
 * Created on August 19, 2022, 5:34 PM
 */

#ifndef NODEAVL_HPP
#define NODEAVL_HPP
#include "Queue.hpp"

class NodeAVL {
public:
    int data;
    Queue* line;
    NodeAVL *left;
    NodeAVL *right;
    int height;

    NodeAVL(Queue* vr, NodeAVL *sl, NodeAVL *sg);
    NodeAVL(Queue* vr, NodeAVL *sl);
    NodeAVL(Queue* vr);
};


#endif /* NODEAVL_HPP */

