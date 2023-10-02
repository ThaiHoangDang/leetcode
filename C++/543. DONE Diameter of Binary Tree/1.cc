#include <vector>
#include <deque>
#include <cmath>
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

void maxPath(TreeNode *root, int &curMax) {

    if (root != nullptr) {
        maxPath(root->left, curMax);
        maxPath(root->right, curMax);

        int left = (root->left == nullptr) ? 0 : root->left->val;
        int right = (root->right == nullptr) ? 0 : root->right->val;

        curMax = (left + right + 1 > curMax) ? left + right + 1 : curMax;

        root->val = max(left, right) + 1;
    }
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int curMax = 0;
        
        maxPath(root, curMax);
        
        return curMax - 1;
    }
};