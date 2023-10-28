#include <vector>
#include <cmath>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remain = 0, sum;
        ListNode *returnedList = l1, *previous;

        while (l1 || l2) {
            if (l1 && l2) {
                sum = l1->val + l2->val + remain; l2 = l2->next;
            } else if (l1) {
                sum = l1->val + remain;
            } else if (l2) {
                swap(l1, l2); previous->next = l1; sum = l1->val + remain;
            }

            if (sum < 10) {
                l1->val = sum; remain = 0;
            } else if (sum < 20) {
                l1->val = sum % 10; remain = 1;
            } else {
                l1->val = sum % 20; remain = 2;
            }
            previous = l1; l1 = l1->next; 
        }

        if (remain == 1) previous->next = new ListNode(1);

        return returnedList;
    }
};