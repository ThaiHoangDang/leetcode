#include <vector>
#include <string>
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
    void recTraverse(TreeNode *node, string s, vector<string> &result) {

        if (node != nullptr) {

            if (s == "") s += to_string(node->val);
            else s += ("->" + to_string(node->val));

            if (node->left == nullptr && node->right == nullptr) result.emplace_back(s);

            if (node->left) recTraverse(node->left, s, result);
            if (node->right) recTraverse(node->right, s, result);
        }
    } 

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        recTraverse(root, "", result);

        return result;
    }
};
