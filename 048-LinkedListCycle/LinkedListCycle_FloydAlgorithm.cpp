#include <iostream>
#include "LinkedList\LinkedList.hpp"

class Solution
{
public:
    bool hasCycle(Node<int> *head)
    {
        if(!head||!head->next){return false;}
        Node<int>* fast = head;
        Node<int>* slow = head;
        while( fast && (fast->next) ){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};

/**
 * Algorithm Steps:
 *   1) Initialize two pointers:
 *          slow and fast, both starting at the head of the linked list.
 *   2) Traverse the linked list:
 *          Move slow one step at a time: slow = slow->next.
 *          Move fast two steps at a time: fast = fast->next->next.
 *   3) Check for a cycle:
 *          If slow == fast at any point, the linked list has a cycle.
 *          If fast or fast->next becomes nullptr, the linked list has no cycle.
 * 
 * Complexity:
 *       Time Complexity:  O(n), where 𝑛 is the number of nodes in the linked list.
 *                           "Each node is visited at most once."
 *       Space Complexity: O(1), as no extra space is used apart from the pointers.
 */

int main()
{
    Solution sl;
    LinkedList<int> ll;
    ll.insertEnd(1);ll.insertEnd(2);ll.insertEnd(3);ll.insertEnd(4);ll.insertEnd(5);ll.insertEnd(6);
    //making it a cycle list making tail point to head or any other cycle 4th points to 2nd
    Node<int>* tail = *ll.getHeader();
    for(int i=0;i<ll.getSize()-1;++i){
        tail = tail->next;
    }
    tail->next = (*ll.getHeader());
    bool re = sl.hasCycle( (*ll.getHeader()) );
    std::cout << re;

    return 0;
}