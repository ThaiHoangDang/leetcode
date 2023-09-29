#include <vector>
#include <cmath>
using namespace std;

// runtime: O(n)
// space: O(m) height of tree for call stack

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (root == nullptr) return 0;

        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        return max(maxLeft, maxRight) + 1;
    }
};