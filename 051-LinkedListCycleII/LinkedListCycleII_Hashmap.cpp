#include <iostream>
#include <unordered_set>
#include "LinkedList\LinkedList.hpp"

/**
 * @b Time_Complixity  @b O(N)
 * @b Space_Complexity @b O(N)
 */
class Solution
{
public:
    Node<int> *detectCycle(Node<int> *head)
    {
        std::unordered_set<Node<int>*> nodeSet;
        while(head)
        {
            if(nodeSet.count(head))
            {
                return head;
            }
            else
            {
                nodeSet.insert(head);
            }
            head = head->next;
        }
        return nullptr;
    }
};

int main()
{
    LinkedList<int> list;
    list.insert(3);
    list.insert(2);
    list.insert(0);
    list.insert(-4);
    //make last node point to 2nd node
    Node<int>* head = *list.getHeader();
    Node<int>* tail=*list.getHeader();
    Node<int>* prev=nullptr;
    while(tail){
        prev = tail;
        tail = tail->next;
    }
    tail = prev;
    tail->next = (*list.getHeader())->next;

    Solution sol;
    Node<int>* res = sol.detectCycle(*list.getHeader());
    std::cout << res->data<<std::endl;res=res->next;
    std::cout << res->data<<std::endl;res=res->next;
    std::cout << res->data<<std::endl;res=res->next;
    std::cout << res->data<<std::endl;res=res->next;


    return 0;
}