#include <vector>
using namespace std;

// approach: recursion
// runtime: O(n^2) ? not sure
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
    bool sameTree(TreeNode *first, TreeNode *second) {
        
        if (first == nullptr && second == nullptr) return true;
        else if (first == nullptr || second == nullptr || first->val != second->val) return false;
        else return sameTree(first->left, second->left) && sameTree(first->right, second->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;

        if (sameTree(root, subRoot)) return true; // check if current tree is the same as subtree
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // check children
    }
};