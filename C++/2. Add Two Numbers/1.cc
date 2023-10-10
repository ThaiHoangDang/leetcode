#include <vector>
#include <cmath>

using namespace std;

// runtime: O()
// space: O()

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remain = 0, sum;
        ListNode *returnedList = l1;

        while (l1) {
            sum = l1->val + l2->val + remain;

            if (sum < 10) {
                l1->val = sum;
            } else if (sum < 20) {
                l1->val = sum % 10; remain = 1;
            } else {
                l1->val = sum % 20; remain = 2;
            }
            l1 = l1->next; l2 = l2->next;
        }

        return returnedList;
    }
};