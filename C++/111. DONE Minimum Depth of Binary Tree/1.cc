#include <vector>
#include <deque>
using namespace std;

// runtime: O(n)
// space: O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NodeLevel {
    TreeNode *node;
    int level;

    NodeLevel(TreeNode *node, int level): node {node}, level {level} {}
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        deque<NodeLevel> queue;

        queue.emplace_back(root, 0);

        while ((! queue.empty()) && root) {
            NodeLevel curNode = queue.at(0);
            queue.pop_front();

            if (curNode.node->left == nullptr && curNode.node->right == nullptr) {
                return curNode.level + 1;
            }

            if (curNode.node->left) queue.emplace_back(curNode.node->left, curNode.level + 1);
            if (curNode.node->right) queue.emplace_back(curNode.node->right, curNode.level + 1);
        }

        return 0;
    }
};