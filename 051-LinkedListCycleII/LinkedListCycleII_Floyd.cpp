#include <iostream>
#include "LinkedList\LinkedList.hpp"

// Floyed's algorithm "TORTOISE & HARE"
/**
 * @b Time_Complixity  @b O(N)
 * @b Space_Complexity @b O(1)
 */
class Solution
{
public:
    Node<int> *detectCycle(Node<int> *head)
    {
        if (!head || !(head->next))
        {
            return nullptr;
        }
        Node<int> *fast = head;
        Node<int> *slow = head;
        // Detect if cycle exists
        while (fast && fast->next)
        {
            slow = slow->next;// Tortoise
            fast = fast->next->next;// Hare

            // Cycle detected
            if (slow == fast)
            {
                // Move one pointer to head
                slow = head;
                // Move both pointers one step a time
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Cycle start found
                return slow;
            }
        }
        // Reaching here means there's no cycle
        return nullptr;
    }
};

int main()
{
    LinkedList<int> list;
    list.insert(3);
    list.insert(2);
    list.insert(0);
    list.insert(4);
    list.insert(9);
    list.insert(8);
    list.insert(1);
    Node<int> *head = *list.getHeader();
    Node<int> *tail = head;
    Node<int> *prev = nullptr;
    while (tail)
    {
        prev = tail;
        tail = tail->next;
    }
    tail = prev;
    tail->next = head->next->next->next;

    Solution sol;
    Node<int> *res = sol.detectCycle(head);
    std::cout << res->data << std::endl;
    res = res->next;
    std::cout << res->data << std::endl;
    res = res->next;
    std::cout << res->data << std::endl;
    res = res->next;
    std::cout << res->data << std::endl;
    res = res->next;

    return 0;
}