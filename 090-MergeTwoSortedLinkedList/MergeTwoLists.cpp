#include <iostream>
#include "LinkedList\LinkedList.hpp"

class Solution
{
public:
    Node<int> *mergeTwoLists(Node<int> *list1, Node<int> *list2)
    {
        Node<int> dummy(0);
        Node<int> *current = &dummy;

        while(list1 && list2)
        {
            if(list1->data <= list2->data)
            {
                current->next = list1;
                list1 = list1->next;
            }else{
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = list1?list1:list2;
        return dummy.next;
    }
};

std::ostream &operator<<(std::ostream &os, Node<int> *head)
{
    os << "[";
    while (head)
    {
        os << head->data;
        os << ",";
        head = head->next;
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    LinkedList<int> list1;
    LinkedList<int> list2;
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);

    list2.insert(1);
    list2.insert(3);
    list2.insert(4);
    Solution sol;
    std::cout << sol.mergeTwoLists(list1.getHeader(), list2.getHeader());
    return 0;
}