#include <iostream>
#include <unordered_set>
#include "LinkedList/LinkedList.hpp"

class Solution
{
public:
    Node<int> *getIntersectionNode(Node<int> *headA, Node<int> *headB)
    {
        std::unordered_set<Node<int>*> setA;
        while(headA)
        {
            setA.insert(headA);
            headA = headA->next;
        }

        while(headB)
        {
            if(setA.count(headB))
            {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};

int main()
{
    LinkedList<int> lA;
    LinkedList<int> lB;
    lA.insert(4);
    lA.insert(1);
    lA.insert(8);
    lA.insert(4);
    lA.insert(5);

    lB.insert(5);
    lB.insert(6);
    lB.insert(1);

    Node<int> *headA = *lA.getHeader();
    Node<int> *headB = *lB.getHeader();
    headA = headA->next->next;
    headB = headB->next->next;
    headB->next = headA;

    Solution sol;
    Node<int> *res = sol.getIntersectionNode(*lA.getHeader(), *lB.getHeader());
    std::cout << res->data;
    std::cout << lA;
    std::cout << lB;
    return 0;
}