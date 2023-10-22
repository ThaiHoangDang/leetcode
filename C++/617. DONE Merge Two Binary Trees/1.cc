#include <vector>
using namespace std;

// approach: recursive, creating new tree
// time: O(n)
// space: O(n), more space than 2.cc


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (root1 && root2) {
            TreeNode *node = new TreeNode(root1->val + root2->val);
            node->left = mergeTrees(root1->left, root2->left);
            node->right = mergeTrees(root1->right, root2->right);
            return node;

        } else if (root1) {
            TreeNode *node = new TreeNode(root1->val);
            node->left = mergeTrees(root1->left, nullptr);
            node->right = mergeTrees(root1->right, nullptr);
            return node;

        } else if (root2) {
            TreeNode *node = new TreeNode(root2->val);
            node->left = mergeTrees(root2->left, nullptr);
            node->right = mergeTrees(root2->right, nullptr);
            return node;

        } else return nullptr;
    }
};
