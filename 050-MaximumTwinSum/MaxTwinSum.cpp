#include <iostream>
#include "LinkedList/LinkedList.hpp"

class Solution
{
public:
    int pairSum(Node<int> *head)
    {
        Node<int>* fast = head;
        Node<int>* slow = head;
        //get middle of list
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse from middle
        Node<int>* prev = nullptr;
        Node<int>* current = slow;
        while(current)
        {   
            Node<int>* nextTmp = current->next;
            current->next = prev;
            prev = current;
            current = nextTmp;
        }

        int max=0;
        while(prev)
        {
            int tmp = head->data + prev->data;
            if(tmp > max){max =tmp;}
            head = head ->next;
            prev = prev->next;
        }

        return max;
    }
};

int main()
{
    Solution sol;
    LinkedList<int> ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(2);
    ll.insert(1);

    int res = sol.pairSum(*ll.getHeader());

    std::cout << res << std::endl;

    return 0;
}