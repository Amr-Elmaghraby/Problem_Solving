#include "BinaryTree/BinaryTree.hpp"

class Solution: private BinaryTree<int>
{
public:
    void Recursive(Node* node){
        if(node!=nullptr){
            Node* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            Recursive(node->left);
            Recursive(node->right);
        }
    }
    Node* invertTree(Node* root){
        if(root==nullptr){return root;}

        Recursive(root);

        return root;
    }
};


int main()
{
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    

    Solution sol;

    tree.root = sol.invertTree(tree.root);

    tree.levelOrder();
    return 0;
}