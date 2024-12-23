#include <iostream>
#include "LinkedList/LinkedList.hpp"

class Solution
{
public:
    Node<int> *deleteDuplicates(Node<int> *head)
    {
        if (!head)
        {
            return head;
        }
        Node<int> *current = head;
        while (current->next)
        {
            if (current->data == current->next->data)
            {
                Node<int> *tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};

int main()
{
    LinkedList<int> list;
    // list.insert(1);
    // list.insert(1);
    // list.insert(1);
    // list.insert(1);
    // list.insert(1);
    // list.insert(2);
    // list.insert(2);
    // list.insert(3);
    // list.insert(3);
    // list.insert(4);
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);

    Solution sol;
    Node<int> *head = sol.deleteDuplicates(list.getHeader());
    std::cout << list;
    return 0;
}