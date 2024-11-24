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
    ll.insertEnd(7);
    ll.insertEnd(8);
    ll.insertEnd(9);
    ll.insertEnd(10);
    ll.insertEnd(11);

    std::cout << ll;

    Node<int> **head = ll.getHeader();

    Node<int> *fast = *head;
    Node<int> *slow = *head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<int> *prev = nullptr;
    Node<int> *curr = slow;
    Node<int> *next = slow;
    while (curr)
    {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr = (*head);
    while(prev -> next){
        Node<int>* tmp1 = curr->next;
        Node<int>* tmp2 = prev->next;
        curr -> next = prev;
        prev -> next = tmp1;
        curr = tmp1;
        prev = tmp2; 
    }

    std::cout << ll;

    return 0;
}