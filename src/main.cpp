#include <iostream>
#include "deque.cpp"

using namespace std;

template class Deque<int>;

// There are 10 memory leaks
int main() {
    Deque<int> deque;
    deque.addLast(new int(1));
    deque.addLast(new int(2));
    deque.addLast(new int(3));
    deque.addLast(new int(4));
    deque.addLast(new int(5));
    cout << "Deque:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(deque.getFirst()) << endl;
        deque.removeFirst();
    }
    cout << "Deque:" << endl;
    deque.addFirst(new int(1));
    deque.addFirst(new int(2));
    deque.addFirst(new int(3));
    deque.addFirst(new int(4));
    deque.addFirst(new int(5));
    for (int i = 0; i < 5; i++) {
        cout << *(deque.getLast()) << endl;
        deque.removeLast();
    }
    cout << endl;
    return 0;
}