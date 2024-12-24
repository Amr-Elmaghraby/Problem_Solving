#include "BinaryTree/BinaryTree.hpp"

class Solution : protected BinaryTree<int>
{
    int Recursion(Node* node){
        if(node == nullptr){
            return 0;
        }
        return 1 + std::max(Recursion(node->left),Recursion(node->right));
    }
public:
    int maxDepth(Node *root)
    {
        int maxDepth = Recursion(root);
        return maxDepth;
    }
};

int main()
{
    BinaryTree<int> tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(0);
    tree.insert(20);
    tree.insert(15);
    tree.insert(30);
    tree.levelOrder();
    Solution sol;
    std::cout << sol.maxDepth(tree.root);
    return 0;
}