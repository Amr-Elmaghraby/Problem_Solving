#pragma once
#include <iostream>

template <typename N>
struct Node
{
    N data;
    Node *next;
    Node(N val) : data(val), next(nullptr) {}
};

template <typename N>
class LinkedList
{
private:
    Node<N> *head;
    int size;
    void setHeader(Node<N> *head)
    {
        this->head = head;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    friend int main();

public:
    LinkedList() : size(0), head(nullptr) {}

    Node<N> *&getHeader()
    {
        return head;
    }

    void insertFront(N val)
    {
        Node<N> *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        ++size;
    }

    void insertEnd(N val)
    {
        Node<N> *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<N> *tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        ++size;
    }

    void insert(N val)
    {
        insertEnd(val);
    }

    void insertAt(int index, N val)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range!!");
        }
        if (index == 0)
        {
            insertFront(val);
        }
        else if (index == size)
        {
            insertEnd(val);
        }
        else
        {
            Node<N> *newNode = new Node(val);
            Node<N> *tmp = head;
            for (int i = 1; i < index; ++i)
            {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            ++size;
        }
    }

    int getSize() { return size; }

    N popFront()
    {
        if (!head)
        {
            throw std::runtime_error("List is empty!!");
        }
        N val = head->data;
        Node<N> *tmp = head;
        head = head->next;
        delete tmp;
        --size;
        return val;
    }

    N peekFront()
    {
        if (!head)
        {
            throw std::runtime_error("List is empty!!");
        }
        return head->data;
    }

    N popBack()
    {
        if (!head)
        {
            throw std::runtime_error("List is empty!!");
        }
        Node<N> *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        N val = tmp->data;
        delete tmp;
        return val;
    }

    N peekBack()
    {
        if (!head)
        {
            throw std::runtime_error("List is empty!!");
        }
        Node<N> *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    N getValAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0)
        {
            return head->data;
        }
        Node<N> *tmp = head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void deleteVal(N val)
    {
        Node<N> *tmp = head;
        Node<N> *prev_tmp = head;
        Node<N> *del = nullptr;
        while (tmp)
        {
            if (tmp->data == val)
            {
                if (tmp == head)
                {
                    head = head->next;
                }
                else
                {
                    prev_tmp->next = tmp->next;
                }
                del = tmp;
                tmp = tmp->next;
                delete tmp;
                continue;
            }
            prev_tmp = tmp;
            tmp = tmp->next;
        }
    }

    void printForward()
    {
        for (Node<N> *current = head; current; current = current->next)
        {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }

    void printBackward()
    {
        Node<N> *tmp = head;
        int itr = size;
        int i = 0;
        while (itr)
        {
            tmp = tmp->next;
            --itr;
            if (itr == 0)
            {
                ++i;
                std::cout << tmp->data << " ";
                tmp = head;
                itr = size - i;
            }
        }
    }

    /**
     * @brief Destroy the Linked List object
     *  Destructor should handle cycled list using Floyd's algorithm to detect cycle if exists
     */
    ~LinkedList()
    {
        if (!head)
        {
            return;
        }

        // DETECT if a CYCLE EXISTS
        Node<N> *fast = head;
        Node<N> *slow = head;
        Node<N> *prev = nullptr;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    /**
                     * Why use prev = fast?
                     *If prev tracked slow's previous node, it might point to a node 
                     * from the non-cyclic part of the list.
                     *prev = fast ensures that prev points to the last node
                     * in the cycle before the start of the cycle.
                     */
                    // prev should be fast prev not slow
                    // as slow is returned to head while fast not
                    // so if prev is slow prev it could be the node
                    // pointing to the cycle begins nodes from
                    // non-cyclic part while fast prev wouldn't
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
                // RETURN with both fast and slow pointing to
                //      the node where cycle begins
                break;
            }
        }

        // Detect if list is
        // fast for even list size
        // fast->next for odd list size
        if (fast && fast->next)
        {
            // make node before cycle begin next pointer a nullptr
            prev->next = nullptr;
        }

        // Deal with list as non-cyclic list even if it was cyclic
        while (head)
        {
            Node<int> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

template <typename N>
std::ostream &operator<<(std::ostream &os, LinkedList<N> &ll)
{
    os << "[";
    for (int i = 0; i < ll.getSize() - 1; ++i)
    {
        os << ll.getValAt(i) << ", ";
    }
    os << ll.getValAt(ll.getSize() - 1);
    os << "]";
    os << std::endl;
    return os;
}

template<typename N>
std::ostream& operator << (std::ostream& os,Node<N>* head){
    if(head == nullptr){return os;}
    os << "[";
    while(head != nullptr){
        os << head->data;
        head = head->next;
        if(head){
            os << ",";
        }
    }
    os<< "]";
    return os;
}