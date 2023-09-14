#include <vector>

using namespace std;

// runtime: O(n)
// space: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curNode = head;

        // skip beginning nodes that have val
        while (curNode != nullptr && curNode->val == val) {
            curNode = curNode->next;
        }

        ListNode *forReturn = curNode;

        while (curNode != nullptr) {
            ListNode *next = curNode->next;

            while (next != nullptr && next->val == val) {
                next = next->next;
            }
            curNode->next = next;
            curNode = curNode->next;
        }

        return forReturn;
    }
};

