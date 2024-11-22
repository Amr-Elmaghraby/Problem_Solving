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

    Node<N> **getHeader()
    {
        return &head;
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

    ~LinkedList()
    {
        while (size)
        {
            Node<N> *tmp = head;
            head = head->next;
            --size;
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