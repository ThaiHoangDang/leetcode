#include <vector>
using namespace std;

// runtime: O(n)
// space: O(m) number of leaves

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}
};

struct NodeDepth {
    TreeNode *node;
    int depth;

    NodeDepth(TreeNode *node, int depth): node {node}, depth {depth} {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;

        if (root == nullptr) return maxDepth;

        vector<NodeDepth> stack;
        stack.emplace_back(root, 1);

        while (! stack.empty()) {
            NodeDepth node = stack.back(); stack.pop_back();

            if (node.node->left == nullptr && node.node->right == nullptr && node.depth >= maxDepth) maxDepth = node.depth;

            if (node.node->left) stack.emplace_back(node.node->left, node.depth + 1);
            if (node.node->right) stack.emplace_back(node.node->right, node.depth + 1);
        }

        return maxDepth;
    }
};