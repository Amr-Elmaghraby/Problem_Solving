#include <iostream>

template <typename valType>
struct Node
{
    valType val;
    Node *next;
    Node *random;
    Node(valType val) : val(val), next(nullptr), random(nullptr) {}
};

template <typename valtype>
class Solution
{
public:
    Node<valtype> *copyRandomList(Node<valtype> *head)
    {
        if(!head){return nullptr;}

        Node<valtype> *current = head;

        // Create Copy nodes interleaving with original list
        // ex list = 7 -> 13 -> 11 -> 10 -> 1 -> nullptr 
        // list interleaves with new nodes
        // 7 |       |-> 13  |      |-> 11 |      |-> 10 |      |-> 1 |     |->   nullptr
        //   |->  7  |       |-> 13 |      |-> 11 |      |-> 10 |     |-> 1 |   
        while(current)
        {
            Node<valtype> *newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Assign random pointers for the new nodes
        current = head;
        while(current)
        {
            if(current->random)
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Separate two lists
        current = head;
        Node<valtype> *copyHead = head->next;
        Node<valtype> *copy = copyHead;
        while(current)
        {
            current->next=current->next->next;
            if(copy->next)
            {
                copy->next = copy->next->next;
            }
            current = current->next;
            copy = copy->next;
        }
        return copyHead;
    }
};

std::ostream &operator<<(std::ostream &os, Node<int> *head)
{
    os << "[";
    while (head->next)
    {
        os << head->val << ", ";
        head = head->next;
    }
    os << head->val;
    os << "]";
    return os;
}

int main()
{
    Node<int> *head = new Node(7);
    Node<int> *copyHead = head;
    {
        Node<int> *tmp = new Node(13);
        copyHead->next = tmp;
        copyHead = copyHead->next;
    }
    {
        Node<int> *tmp = new Node(11);
        copyHead->next = tmp;
        copyHead = copyHead->next;
    }
    {
        Node<int> *tmp = new Node(10);
        copyHead->next = tmp;
        copyHead = copyHead->next;
    }
    {
        Node<int> *tmp = new Node(1);
        copyHead->next = tmp;
        copyHead = copyHead->next;
    }
    {
        head->random = nullptr;
        head->next->random = head;
        head->next->next->random = head->next->next->next->next;
        head->next->next->next->random = head->next->next;
        head->next->next->next->next->random = head;
    }

    Solution<int> sol;
    Node<int>* res = sol.copyRandomList(head);
    std::cout << res; 

    return 0;
}