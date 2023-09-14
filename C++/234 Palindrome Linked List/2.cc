#include <vector>
#include <cmath>

using namespace std;

// runtime: O(n)
// space: O(n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head, int &track) {
        ListNode *curNode = head;
        ListNode *mid = head;

        while (curNode->next != nullptr) {
            curNode = curNode->next;
            
            if (track % 2 == 1) {
                mid = mid->next;
            }

            track++;
        }

        return mid;
    }

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

    bool isPalindrome(ListNode* head) {
        int track = 1;
        ListNode *tail = reverseList(middleNode(head, track));

        for (int i = 0; i < track / 2; i++) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }
};
