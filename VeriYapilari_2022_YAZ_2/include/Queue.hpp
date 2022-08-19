
/* 
 * File:   Queue.hpp
 * Author: HAKAN KIRIK
 *
 * Created on August 18, 2022, 11:13 PM
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"

class Queue {
private:
    Node *front;
    Node *back;
    int length;

    Node* previousMaxNode();
public:
    Queue();
    int count()const;
    bool isEmpty()const;
    void enqueue(const int& item);
    void dequeue();
    void dequeueMax();
    void clear();
    int& peek()const;
    int& peekMax();
    int sumQueue();
    ~Queue();
};


#endif /* QUEUE_HPP */

