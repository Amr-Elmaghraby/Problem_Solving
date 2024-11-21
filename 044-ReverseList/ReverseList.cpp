#include <iostream>
#include "LinkedList\LinkedList.hpp"

int main()
{
    LinkedList<int> ll;
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(5);
    ll.insertEnd(6);

    std::cout << ll;
    std::cout << ll.getSize() << std::endl;

    Node<int> **head = ll.getHeader();

    Node<int>* prev = nullptr;
    Node<int>* curr = (*head);
    Node<int>* next = (*head);
    while(curr){
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ll.setHeader(prev);
    std::cout << ll;

    return 0;
}