#include <vector>

using namespace std;

// HAY!!!
// arroach: let fast goes first n node, then move two ptrs together until fast reaches the end!!!
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *fast = head, *slow = head;

        // let fast goes first
        for (int i = 0; i < n; i++) { fast = fast->next; }

        // special case when the removing node is the first node
        if (fast == nullptr) { return head->next; }

        // move two ptrs
        while (fast->next != nullptr) {
            fast = fast->next; slow = slow->next;
        }

        // skip the target node
        slow->next = slow->next->next;

        return head;
    }
};
