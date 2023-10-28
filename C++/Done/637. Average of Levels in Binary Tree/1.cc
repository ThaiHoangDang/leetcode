#include <vector>
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

void treeTraverse(TreeNode *node, int level, vector<vector<int>> &holder) {

    if (node != nullptr) {

        if (holder.size() < level + 1) holder.emplace_back(vector<int> {node->val});
        else holder.at(level).emplace_back(node->val);

        treeTraverse(node->left, level + 1, holder);
        treeTraverse(node->right, level + 1, holder);
    }
}

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<vector<int>> holder;

        treeTraverse(root, 0, holder);

        for (int i = 0; i < holder.size(); i++) {
            double sum = 0;

            for (auto j : holder[i]) {
                sum += j;
            }

            result.emplace_back(sum / holder[i].size());
        }

        return result;
    }
};