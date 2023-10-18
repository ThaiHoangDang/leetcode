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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        ListNode *last = head, *cur = head->next, *next = nullptr;
        head->next = nullptr;

        for (int i = 0; i < right - left; i++) {
            next = cur->next;

            cur->next = last;
            last = cur;
            cur = next;
        }

        return last;
    }
};
