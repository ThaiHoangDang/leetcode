using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool recSearch(TreeNode *root, TreeNode *target) {

        if (root == target) return true;
        else if (root != nullptr) return recSearch(root->left, target) || recSearch(root->right, target);
        else return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == p || root == q) return root;
    
        while (true) {

            if (recSearch(root->left, p) && recSearch(root->left, q)) {
                root = root->left;
            } else if (recSearch(root->right, p) && recSearch(root->right, q)) {
                root = root->right;
            } else break;
        }

        return root;
    }
};
