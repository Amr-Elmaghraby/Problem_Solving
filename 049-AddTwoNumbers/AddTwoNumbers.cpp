#include <iostream>
#include "LinkedList\LinkedList.hpp"

class Solution
{
public:
    Node<int> *addTwoNumbers(Node<int> *l1, Node<int> *l2)
    {
        Node<int> *dummy = new Node<int>(0);
        Node<int> *current = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = 0;
            int result = 0;
            if (l1 && l2)
            {
                sum = (l1->data + l2->data + carry);
                result = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                sum = (l1->data + carry);
                result = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
            }
            else if (l2)
            {
                sum = (l2->data + carry);
                result = sum % 10;
                carry = sum / 10;
                l2 = l2->next;
            }
            else
            {
                result = carry;
                carry = 0;
            }
            current->next = new Node<int>(result);
            current = current->next;
        }
        Node<int> *head = dummy->next;
        delete dummy;
        return head;
    }
};

std::ostream &operator<<(std::ostream &os, Node<int> *head)
{
    if (!head)
    {
        os << 0;
        return os;
    }
    os << "[";
    while (head)
    {
        os << head->data;
        if (head->next)
        {
            os << ", ";
            head = head->next;
        }
        else
            break;
    }
    os << "]" << std::endl;
    return os;
}

int main()
{
    Solution sl;
    LinkedList<int> l1;
    l1.insertEnd(9);
    l1.insertEnd(9);
    l1.insertEnd(9);
    l1.insertEnd(9);
    l1.insertEnd(9);
    l1.insertEnd(9);
    l1.insertEnd(9);
    LinkedList<int> l2;
    l2.insertEnd(9);
    l2.insertEnd(9);
    l2.insertEnd(9);
    l2.insertEnd(9);

    Node<int> *res = sl.addTwoNumbers(*l1.getHeader(), *l2.getHeader());

    std::cout << res;

    return 0;
}