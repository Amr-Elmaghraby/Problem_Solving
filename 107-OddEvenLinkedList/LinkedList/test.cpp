#include <iostream>

template <typename N>
class LinkedList
{
private:

    struct Node
    {
        N data;
        Node* next;
        Node(N val): data(val), next(nullptr){}
    };
    Node *head;
    int size;

    /**
     * @brief Sets the head of the linked list (used internally).
     * @param head Pointer to the new head node.
     */
    void setHeader(Node *head)
    {
        this->head = head;
    }

    /**
     * @brief Sets the size of the linked list (used internally).
     * @param size New size of the linked list.
     */
    void setSize(int size)
    {
        this->size = size;
    }

    friend int main();

public:
    /**
     * @brief Constructs an empty LinkedList.
     */
    LinkedList() : size(0), head(nullptr) {}

    /**
     * @brief Returns the head pointer of the linked list.
     * @return A double pointer to the head node.
     */
    Node *&getHeader()
    {
        return head;
    }

    /**
     * @brief Inserts a new value at the front of the list.
     * @param val Value to insert.
     */
    void insertFront(N val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    /**
     * @brief Inserts a new value at the end of the list.
     * @param val Value to insert.
     */
    void insertEnd(N val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = newNode;
        }
        ++size;
    }

    /**
     * @brief Insert given value at end of list
     *
     * @param val
     */
    void insert(N val)
    {
        insertEnd(val);
    }

    /**
     * @brief Inserts a value at the specified index.
     * @param index Position to insert the value.
     * @param val Value to insert.
     * @throws std::out_of_range if index is out of bounds.
     */
    void insertAt(int index, N val)
    {
        if (index < 0 || index > size)
            throw std::out_of_range("Index out of range!");
        if (index == 0)
            insertFront(val);
        else if (index == size)
            insertEnd(val);
        else
        {
            Node *newNode = new Node(val);
            Node *tmp = head;
            for (int i = 1; i < index; ++i)
                tmp = tmp->next;
            newNode->next = tmp->next;
            tmp->next = newNode;
            ++size;
        }
    }

    /**
     * @brief Returns the size of the linked list.
     * @return The number of nodes in the list.
     */
    int getSize() { return size; }

    /**
     * @brief Removes and returns the value at the front of the list.
     * @return The value of the front node.
     * @throws std::runtime_error if the list is empty.
     */
    N popFront()
    {
        if (!head)
            throw std::runtime_error("List is empty!");
        Node *tmp = head;
        N val = head->data;
        head = head->next;
        delete tmp;
        --size;
        return val;
    }

    /**
     * @brief Returns the value at the front without removing it.
     * @return The value of the front node.
     * @throws std::runtime_error if the list is empty.
     */
    N peekFront()
    {
        if (!head)
            throw std::runtime_error("List is empty!");
        return head->data;
    }

    /**
     * @brief Removes and returns the value at the back of the list.
     * @return The value of the last node.
     * @throws std::runtime_error if the list is empty.
     */
    N popBack()
    {
        if (!head)
            throw std::runtime_error("List is empty!");
        if (!head->next)
        {
            N val = head->data;
            delete head;
            head = nullptr;
            --size;
            return val;
        }
        Node *tmp = head;
        while (tmp->next && tmp->next->next)
            tmp = tmp->next;
        N val = tmp->next->data;
        delete tmp->next;
        tmp->next = nullptr;
        --size;
        return val;
    }

    /**
     * @brief Just returns the value at the back of the list.
     * @return The value of the last node.
     * @throws std::runtime_error if the list is empty.
     */
    N peekBack()
    {
        if (!head)
        {
            throw std::runtime_error("List is empty!!");
        }
        Node *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    /**
     * @brief Get value at specific given index
     *
     * @param index: index to get value at
     * @return N: value at given index
     */
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
        Node *tmp = head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    /**
     * @brief Delete given value from any node with value
     *
     * @param val: value wanted to be deleted from list
     * @param bool: True for deleting all nodes with the value "DEFAULT"
     *              False just deleting first occurense
     */
    void deleteVal(N val, bool all = true)
    {
        Node *current = head;
        Node *prev = nullptr;
        while (current)
        {
            if (current->data == val)
            {
                if (current == head)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = current->next;
                }
                Node *tmp = current;
                current = current->next;
                delete tmp;
                --size;
                if (all)
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
            prev = current;
            current = current->next;
        }
    }

    /**
     * @brief Prints the list from front to back.
     */
    void printForward()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prints the list from end to front
     */
    void printBackward()
    {
        Node *tmp = head;
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
        Node *fast = head;
        Node *slow = head;
        Node *prev = nullptr;
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
            Node *tmp = head;
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

int main()
{
    LinkedList<int> ll;
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(5);
    ll.insertEnd(6);

    std::cout << ll;
    std::cout << ll.getSize() << std::endl;

    struct LinkedList<int>::Node *head = ll.getHeader();

    std::cout << ll;

    auto *next = (head)->next;
    auto *tmp = (head);
    int size = 1;
    while (tmp->next)
    {
        tmp = tmp->next;
        ++size;
    }
    (head)->next = tmp;
    int i = 0;
    while (tmp != next)
    {
        tmp->next = next;
        tmp = next->next;
        for (int j = (i + 2); j < (size - i - 2); ++j)
        {
            tmp = tmp->next;
        }
        auto *t = next->next;
        next->next = tmp;
        next = t;
        ++i;
    }
    if (!(size % 2))
    {
        next->next = nullptr;
    }
    else
    {
        next->next->next = nullptr;
    }

    std::cout << ll;

    std::cout << ll.peekFront() << std::endl;
    std::cout << ll.peekBack();

    auto *second = (ll.getHeader());
    second = second->next;
    ll.setHeader(second);
    ll.setSize(ll.getSize() - 1);
    std::cout << ll;

    // test deleteVal default parameter value if not passed
    std::cout << "***********************************************" << std::endl;
    LinkedList<int> li;
    li.insert(1);
    li.insert(2);
    li.insert(3);
    li.insert(99);
    li.insert(4);
    li.insert(5);
    li.insert(99);
    std::cout << li;
    li.deleteVal(99);
    std::cout << li;

    return 0;
}