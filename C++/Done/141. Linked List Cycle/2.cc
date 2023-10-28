#include <vector>
using namespace std;

// runtime: O(n)
// space: O(1)


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;

        while (slow && fast) {
            slow = slow->next;
            fast = (fast->next == NULL) ? fast->next : fast->next->next;
            count++;

            if (slow == fast && count > 1) return true;
        }

        return false;
    }
};