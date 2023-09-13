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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *last = head, *cur = head->next, *next = nullptr;
        head->next = nullptr;

        while (cur) {
            next = cur->next;

            cur->next = last;
            last = cur;
            cur = next;
        }

        return last;
    }
};
