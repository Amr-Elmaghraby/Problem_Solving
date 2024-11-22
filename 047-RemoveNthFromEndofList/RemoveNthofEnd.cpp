#include <iostream>
#include "LinkedList\LinkedList.hpp"


class Solution{
    public:
    Node<int>* removeNthFromEnd(Node<int>* head,int n){
        if(!head){return 0;}
        Node<int>* dummy = new Node<int>(0);
        dummy -> next = head;
        Node<int>* fast = dummy;
        Node<int>* slow = dummy;
        for(int i=0; i <= n; ++i){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow=slow->next;
        }
        Node<int>* todelete = slow->next; 
        slow->next = slow->next->next;
        delete todelete;
        head = dummy->next;
        return head;
    }

};



int main(){
    Solution sl;
    LinkedList<int> ll;
    // ll.insertEnd(1);ll.insertEnd(2);ll.insertEnd(3);ll.insertEnd(4);ll.insertEnd(5);
    ll.insertEnd(1);ll.insertEnd(2);
    std::cout << "LinkedList before Removing Nth Node: " <<ll;
    Node<int>* head = sl.removeNthFromEnd( (*ll.getHeader()) ,2);
    ll.setHeader(head);
    ll.setSize(ll.getSize()-1);

    std::cout <<"LinkedList after Removing Nth Node: "<<ll;

    return 0;
}