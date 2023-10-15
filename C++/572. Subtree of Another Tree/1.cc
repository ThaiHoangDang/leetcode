#include <vector>
using namespace std;

// approach: recursion
// runtime: O(nm) ? not sure
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

        // return false if current nodes are not the same
        else if (first == nullptr || second == nullptr || first->val != second->val) return false;

        // recursively check children
        else return sameTree(first->left, second->left) && sameTree(first->right, second->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if (root == nullptr) return false;

        // check if current tree is the same as subtree
        if (sameTree(root, subRoot)) return true; 
        
        // recursively check children
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }
};