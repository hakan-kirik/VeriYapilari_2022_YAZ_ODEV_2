

#include "Queue.hpp"

Node* Queue::previousMaxNode() {
    Node *prev = 0;
    Node *tmp = front;
    int max = front->item;
    while (tmp->next != 0) {
        if (tmp->next->item > max) {
            max = tmp->next->item;
            prev = tmp;
        }
        tmp = tmp->next;
    }
    return prev;
}

Queue::Queue() {
    front = back = 0;
    length = 0;
}

int Queue::count()const {
    return length;
}

bool Queue::isEmpty()const {
    return length == 0;
}

void Queue::enqueue(const int& item) {
    Node *last = new Node(item);
    if (isEmpty()) front = back = last;
    else {
        back->next = last;
        back = back->next;
    }
    length++;
}

void Queue::dequeue() {
    if (isEmpty()) throw "Queue is Empty";
    Node *tmp = front;
    front = front->next;
    delete tmp;
    length--;
}

void Queue::dequeueMax() {
    if (isEmpty()) throw "Queue is Empty";
    Node *prev = previousMaxNode();
    Node *tmp;
    if (prev == 0) dequeue();
    else {
        if (prev->next == back) back = prev;
        tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        length--;
    }
}

void Queue::clear() {
    while (!isEmpty())dequeue();
}

int& Queue::peek()const {
    if (isEmpty()) throw "Queue is Empty";
    return front->item;
}

int& Queue::peekMax() {
    if (isEmpty()) throw "Queue is Empty";
    Node *prev = previousMaxNode();
    if (prev == 0) return peek();
    return prev->next->item;
}

int Queue::sumQueue() {
    if (front == 0) throw "Queue is empty";
    if (front->next == 0) return front->item;
    Node * tmp = front;
    int total = 0;
    while (tmp != 0) {
        total += tmp->item;
        tmp = tmp->next;
    }
    return total;
}

Queue::~Queue() {
    clear();
}
