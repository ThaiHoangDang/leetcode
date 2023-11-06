#include <vector>
using namespace std;

// arroach: List traverse
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *curNode = head, *previousNode = nullptr;
        int length = 0;

        // find the length
        while (curNode) { length++; curNode = curNode->next; }

        // special case
        if (length == 1) return nullptr;

        // reset curNode to head
        curNode = head;

        // find the removing node
        for (int i = 0; i < length / 2; i++, previousNode = curNode, curNode = curNode->next);

        previousNode->next = curNode->next;

        return head;        
    }
};
