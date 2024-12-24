#include "BinaryTree/BinaryTree.hpp"
#include <queue>

class Solution : protected BinaryTree<int>
{
public:
    int maxDepth(Node *root)
    {
        if(root == nullptr){return 0;}
        int maxDepth=0;
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            // Number of nodes at the current level
            int levelNodes = q.size();
            // Increment depth for each level
            ++maxDepth;
            for (size_t i = 0; i < levelNodes; i++)
            {
                Node* current = q.front();
                q.pop();
                // Push children of the current nod into the queue
                if(current->left){q.push(current->left);}
                if(current->right){q.push(current->right);}
            }
        }
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