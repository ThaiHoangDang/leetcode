#include <vector>
#include <cmath>

using namespace std;

// runtime: O(n)
// space: O(n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>vals;
        ListNode *curNode = head;

        while (curNode) {
            vals.emplace_back(curNode->val);
            curNode = curNode->next;
        }

        for (int i = 0; i < ceil(vals.size() / 2); i++) {
            if (vals.at(i) != vals.at(vals.size() - i - 1)) return false;
        }

        return true;
    }
};