#pragma once

template <class E>
struct doublyLinkedNode {
    E* data;
    doublyLinkedNode* next;
    doublyLinkedNode* prev;
};

template <class E>
class Deque {
private:
    struct doublyLinkedNode<E>* circularHead;
public:
    Deque();
    ~Deque();
    E* getFirst();
    E* getLast();
    void addFirst(E*);
    void addLast(E*);
    bool removeFirst();
    bool removeLast();
};
