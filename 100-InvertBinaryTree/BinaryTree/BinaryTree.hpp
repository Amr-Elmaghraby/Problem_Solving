#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution;

template <typename dType>
class BinaryTree
{
protected:
    struct Node
    {
        dType data;
        Node *left;
        Node *right;
        // Constructor to initialize the node
        Node(dType data) : data(data), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;

    // Helper function for pre-order traversal
    void preOrderHelper(Node *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    // Helper function for in-order traversal
    void inOrderHelper(Node *node)
    {
        if (node != nullptr)
        {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    // Helper function for post-order Traversal
    void postOrderHelper(Node *node)
    {
        if (node != nullptr)
        {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            std::cout << node->data << " ";
        }
    }

    // Helper function for level-order traversal (BFS)
    void levelOrderHelper(Node *node)
    {
        if (node == nullptr)
            return;

        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
    }

    // Helper function to find the height of the tree
    int heightHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }

    // Helper function to check if the tree is balanced
    bool isBalancedHelper(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }

        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);

        return abs(leftHeight - rightHeight) <= 1 &&
               isBalancedHelper(node->left) &&
               isBalancedHelper(node->right);
    }

    // Helper function to find the minimum node in a subtrre
    Node *findMinHelper(Node *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node from the tree
    Node *deleteHelper(Node *node, dType val)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (val < node->data)
        {
            node->left = deleteHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteHelper(node->right, val);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                Node *tmp = node->right;
                delete node;
                return tmp;
            }
            else if (node->right == nullptr)
            {
                Node *tmp = node->left;
                delete node;
                return tmp;
            }

            // Node with two children
            Node *tmp = findMinHelper(node->right);

            // Copy the inorder successor's content to this node
            node->data = tmp->data;

            // Delete the inorder successor
            node->right = deleteHelper(node->right, tmp->data);
        }
        return node;
    }

    // Helper function to search for a value in the tree
    Node* searchHelper(Node* node, int val)
    {

        while (node)
        {
            if (val > node->data)
            {
                node = node->right;
            }
            else if (val < node->data)
            {
                node = node->left;
            }
            else
            {
                return node;
            }
        }

        return node;
    }

    friend int main();
public:
    // Constructor to initialize the root
    BinaryTree()
    {
        root = nullptr;
    }

    BinaryTree(dType val)
    {
        root = new Node(val);
    }

    // Insert a new node in the binary search tree
    void insert(dType val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
        }
        else
        {
            Node *tmp = root;
            while (true)
            {
                if (val < tmp->data)
                {
                    if (tmp->left == nullptr)
                    {
                        tmp->left = new Node(val);
                        break;
                    }
                    tmp = tmp->left;
                }
                else
                {
                    if (tmp->right == nullptr)
                    {
                        tmp->right = new Node(val);
                        break;
                    }
                    tmp = tmp->right;
                }
            }
        }
    }

    // Pre-order traversal
    void preOrder(){
        preOrderHelper(root);
        std::cout << std::endl;
    }

    // In-order traversal
    void inOrder(){
        inOrderHelper(root);
        std::cout << std::endl;
    }

    // Post-order traversal
    void postOrder(){
        postOrderHelper(root);
        std::cout << std::endl;
    }

    // Level-order (BFS) traversal
    void levelOrder(){
        levelOrderHelper(root);
        std::cout << std::endl;
    }
    void BFS(){
        levelOrder();
    }

    // Find the height of the tree
    int height(){
        return heightHelper(root);
    }

    // check if the tree is balanced
    bool isBalanced()
    {
        return isBalancedHelper(root);
    }

    // Delete a node from the tree
    void deleteNode(dType val){
        root = deleteHelper(root,val);
    }

    // Search for a node with a specific value
    bool search(dType val){
        Node* result = searchHelper(root,val);
        return result != nullptr;
    }

};