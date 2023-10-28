#include <vector>
using namespace std;

// runtime: O(n)
// space: O(1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}
};

struct SumNode {
    TreeNode *node;
    int sum;

    SumNode(TreeNode *node, int sum): node {node}, sum {sum} {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (! root) return false;

        vector<SumNode> stack;
        stack.emplace_back(root, root->val);

        while (! stack.empty()) {
            SumNode item = stack.back(); stack.pop_back();

            if (item.node->left == nullptr && item.node->right == nullptr && 
                item.sum == targetSum) return true;

            if (item.node->left) stack.emplace_back(item.node->left, item.sum + item.node->left->val);
            if (item.node->right) stack.emplace_back(item.node->right, item.sum + item.node->right->val);
        }

        return false;
    }
};