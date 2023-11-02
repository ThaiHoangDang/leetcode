#include <vector>
using namespace std;

// arroach: 2 pointers
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = nullptr, *right = nullptr, *firstRight = nullptr, *firstLeft = nullptr;

        while (head) {
            if (head->val < x) {
                if (left == nullptr) {
                    left = head;
                    firstLeft = head;
                } else {
                    left->next = head; left = head;
                }
            } else {
                if (right == nullptr) {
                    right = head;
                    firstRight = head;
                } else {
                    right->next = head; right = head;
                }
            }
            head = head->next;
        }

        if (right != nullptr) right->next = nullptr;

        if (left != nullptr) {
            left->next = firstRight;
            return firstLeft;
        } else return firstRight;
    }
};
