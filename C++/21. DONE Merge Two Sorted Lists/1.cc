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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, *curNode = nullptr;

        if (list1 && (! list2)) return list1; // return list1 if list2 is nullptr
        if (list2 && (! list1)) return list2; // return list2 if list1 is nullptr
        if ((! list2) && (! list1)) return head; // return nullptr if two lists are nullptr

        // update the first element of the list
        if (list1->val < list2->val) {
            head = list1; curNode = list1; list1 = list1->next;
        } else {
            head = list2; curNode = list2; list2 = list2->next;
        }

        // traverse the two lists and update the combined list
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curNode->next = list1;
                curNode = curNode->next;
                list1 = list1->next;
            } else {
                curNode->next = list2;
                curNode = curNode->next;
                list2 = list2->next;
            }
        }

        // add the remaining list
        if (list1) curNode->next = list1;
        else if (list2) curNode->next = list2;

        return head;
    }
};
