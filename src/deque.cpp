#include "deque.h"

template <class E>
Deque<E>::Deque() {
    circularHead = new struct doublyLinkedNode<E>();
    circularHead->next = circularHead;
    circularHead->prev = circularHead;
}

template <class E>
Deque<E>::~Deque() {
    while (circularHead->next != circularHead) {
        removeFirst();
    }
}

template <class E>
E* Deque<E>::getFirst() {
    return circularHead->next->data;
}

template <class E>
E* Deque<E>::getLast() {
    return circularHead->prev->data;
}

template <class E>
void Deque<E>::addFirst(E* el) {
    struct doublyLinkedNode<E>* tmp = new struct doublyLinkedNode<E>();
    tmp->data = el;
    tmp->prev = circularHead;
    tmp->next = circularHead->next;
    tmp->next->prev = tmp;
    circularHead->next = tmp;
}

template <class E>
void Deque<E>::addLast(E* el) {
    struct doublyLinkedNode<E>* tmp = new struct doublyLinkedNode<E>();
    tmp->data = el;
    tmp->next = circularHead;
    tmp->prev = circularHead->prev;
    tmp->prev->next = tmp;
    circularHead->prev = tmp;
}

template <class E>
bool Deque<E>::removeFirst() {
    if (circularHead->next != circularHead) {
        struct doublyLinkedNode<E>* tmp = circularHead->next;
        circularHead->next = tmp->next;
        tmp->next->prev = circularHead;
        delete tmp;
        return true;
    }
    return false;
}

template <class E>
bool Deque<E>::removeLast() {
    if (circularHead->prev != circularHead) {
        struct doublyLinkedNode<E>* tmp = circularHead->prev;
        circularHead->prev = tmp->prev;
        tmp->prev->next = circularHead;
        return true;
    }
    return false;
}