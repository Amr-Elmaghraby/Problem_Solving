#include <iostream>
#include "LinkedList\LinkedList.hpp"


class Solution
{
    public:
    Node<int>* middleNode(Node<int>*head){
        Node<int> *fast = head;
        Node<int> *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


int main()
{
    LinkedList<int> list;
    // list.insert(1);
    // list.insert(2);
    // list.insert(3);
    // list.insert(4);
    // list.insert(4);
    // list.insert(5);

    Solution sol;
    std::cout<< sol.middleNode(list.getHeader())->data;
    return 0;
}