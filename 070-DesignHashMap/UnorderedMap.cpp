#include <iostream>

class MyHashMap
{
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node(int key, int value) : key(key), value(value), next(nullptr) {}
        Node(int key, int value, Node *next) : key(key), value(value), next(next) {}
        Node() : key(0), value(0), next(nullptr) {}
    };

    Node **buckets;

    size_t size;

    int capacity;

    float sizeThreshold;

    size_t HashFunction(int key) 
    {
        size_t hash = key;

        hash ^= (hash<<21);
        hash *= 2654435761;
        hash ^= (hash<<21);
        hash *= 2654435761;
        hash ^= (hash<<21);
        
        return hash;
    }

    size_t getBucketIndex(int key)
    {
        return HashFunction(key) % capacity;
    }

public:
    MyHashMap(int capacity = 16, float sizeThreshold = 0.8f) : capacity(capacity), sizeThreshold(sizeThreshold),size(0)
    {
        buckets = new Node *[capacity]();
    }

    void put(int key, int value)
    {
        size_t index = getBucketIndex(key);

        Node *current = buckets[index];

        while (current)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node *tmp = new Node(key, value, buckets[index]);
        buckets[index] = tmp;
        ++size;

        if( (float)(size/capacity) >= sizeThreshold)
        {
            reserve(2*capacity);
        }
    }

    int get(int key)
    {
        size_t index = getBucketIndex(key);
        Node *current = buckets[index];
        while (current)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void remove(int key)
    {
        size_t index = getBucketIndex(key);
        Node *current = buckets[index];
        Node* prev = nullptr;
        while (current)
        {
            if(current->key == key)
            {
                --size;
                if(prev == nullptr)
                {
                    prev = buckets[index];
                    buckets[index] = buckets[index] ->next;
                    delete prev;
                    return;
                }
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void reserve(int newCapacity)
    {
        if(newCapacity > capacity)
        {
            Node** newBuckets = new Node*[newCapacity]();
            for(int i=0;i<capacity;++i)
            {
                Node* current = buckets[i];
                while(current)
                {
                    size_t index = HashFunction(current->key) % newCapacity;
                    Node* tmp = new Node(current->key,current->value,newBuckets[index]);
                    newBuckets[index] = tmp;
                    Node* del = current;
                    current = current->next;
                    delete del;
                } 
            }
            buckets = newBuckets;
            capacity = newCapacity;
        }
    }

    ~MyHashMap() 
    {
        for(int i=0;i<capacity;++i)
        {
            Node* current = buckets[i];
            while(current)
            {
                Node* tmp = current;
                current = current->next;
                delete tmp;
            }
        }
    }
};

int main()
{
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << obj->get(1);
    std::cout << obj->get(3);
    obj->put(2, 1);
    std::cout << obj->get(2);
    obj->remove(2);
    std::cout << obj->get(2);

    return 0;
}