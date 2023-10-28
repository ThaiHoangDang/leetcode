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
    ListNode* middleNode(ListNode* head) {
        ListNode *curNode = head;
        ListNode *mid = head;
        int track = 1;

        while (curNode->next != nullptr) {
            curNode = curNode->next;
            
            if (track % 2 == 1) {
                mid = mid->next;
            }

            track++;
        }

        return mid;
    }
};
