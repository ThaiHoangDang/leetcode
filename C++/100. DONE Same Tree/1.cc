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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        deque<TreeNode *> queue1, queue2;

        queue1.emplace_back(p);
        queue2.emplace_back(q);
        
        while ((! queue1.empty()) && (! queue2.empty())) {
            TreeNode *node1 = queue1.at(0); queue1.pop_front();
            TreeNode *node2 = queue2.at(0); queue2.pop_front();

            // add new children nodes to queue if cur nodes are not nullptr and have the same values
            if ((node1 != nullptr) && (node2 != nullptr) && (node1->val == node2->val)) {
                queue1.emplace_back(node1->left); queue1.emplace_back(node1->right);
                queue2.emplace_back(node2->left); queue2.emplace_back(node2->right);
            
            // return false if one of the node is nullptr while the other has an address
            } else if (node1 != node2) return false;
            
        }

        return true;
    }
};