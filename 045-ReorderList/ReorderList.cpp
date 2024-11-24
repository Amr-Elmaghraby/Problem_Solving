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

    std::cout << ll;


    //0r not best practice RorderList2 is better
    
    Node<int> *next = (*head)->next;
    Node<int> *tmp = (*head);
    int size = 1;
    while (tmp->next)
    {
        tmp = tmp->next;
        ++size;
    }
    (*head)->next = tmp;
    int i = 0;
    while (tmp != next)
    {
        tmp->next = next;
        tmp = next->next;
        for (int j = (i + 2); j < (size - i - 2); ++j)
        {
            tmp = tmp->next;
        }
        Node<int> *t = next->next;
        next->next = tmp;
        next = t;
        ++i;
    }
    if (!(size % 2))
    {
        next->next = nullptr;
    }
    else
    {
        next->next->next = nullptr;
    }

    std::cout << ll;

    return 0;
}