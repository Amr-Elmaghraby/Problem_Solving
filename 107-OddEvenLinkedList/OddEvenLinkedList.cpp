#include "LinkedList/LinkedList.hpp"
#include <iostream>
#include <vector>
using namespace std;



class Solution
{
    public:
    Node<int>* oddEvenList(Node<int>* head)
    {
        if(head == nullptr || head->next == nullptr){return head;}

        Node<int>* evenHead = head->next;

        Node<int>* currEven = evenHead;
        Node<int>* currOdd = head;

        while(currEven && currEven->next){
            currOdd->next = currEven->next;
            currOdd = currOdd->next;

            currEven->next = currOdd->next;
            currEven = currEven->next;
        }

        currOdd->next = evenHead;
        return head;
    }  
};


int main()
{
    Solution sol;
    LinkedList<int> ll;
    ll.insert(2);
    ll.insert(1);
    ll.insert(3);
    // ll.insert(5);
    // ll.insert(6);
    // ll.insert(4);

    ll.printForward();

    Node<int>* head = ll.getHeader();

    sol.oddEvenList(head);

    ll.printForward();

    std::cout << head;

    return 0;
}