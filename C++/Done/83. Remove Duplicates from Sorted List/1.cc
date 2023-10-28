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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curNode = head;

        while (curNode) {
            ListNode *next = curNode->next;
            
            while (next != nullptr && next->val == curNode->val) {
                next = next->next;
            }

            curNode->next = next;
            curNode = curNode->next;
        }

        return head;
    }
};