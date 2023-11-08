#include <vector>
using namespace std;

// approach: recursion
// time: O(n)
// space: O(n)


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
    bool sameValues(TreeNode *node1, TreeNode *node2) {
        
        if (node1 == nullptr && node2 == nullptr) return true;
        else if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) return false;
        
        return sameValues(node1->left, node2->right) && sameValues(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return sameValues(root->left, root->right);
    }
};
