#include <iostream>
#include "LinkedList/LinkedList.hpp"

class Solution
{
public:
    Node<int> *getIntersectionNode(Node<int> *headA, Node<int> *headB)
    {
        if (!headA || !headB) return nullptr;

        Node<int>* pA = headA;
        Node<int>* pB = headB;

        // Traverse both lists
        // pA = pA ?  means if(pA != nullptr)
        // This way both pA & pB will only meet at the node of intersection
        // or at nullptr at end of each others  
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA; // either the intersection node or nullptr
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
    // headB->next = headA;

    Solution sol;
    Node<int>* res = sol.getIntersectionNode(*lA.getHeader(),*lB.getHeader());

    std::cout << lA;
    std::cout << lB;
    return 0;
}