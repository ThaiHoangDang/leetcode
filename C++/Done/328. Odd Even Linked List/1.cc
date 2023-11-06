#include <vector>
using namespace std;

// arroach: list traverse
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = nullptr, *even = nullptr, *firstOdd = nullptr, *firstEven = nullptr;
        bool isOdd = true;

        while (head) {

            if (isOdd) {
                if (odd == nullptr) { odd = head; firstOdd = odd; } // first node
                else { odd->next = head; odd = odd->next; } // following nodes
                isOdd = false;

            } else {
                if (even == nullptr) { even = head; firstEven = even; } // first node
                else { even->next = head; even = even->next; } // following nodes
                isOdd = true;
            }

            head = head->next; // update head
        }

        if (even != nullptr) even->next = nullptr; // mark the end of linked list

        if (odd == nullptr) return firstEven;
        
        odd->next = firstEven;
        return firstOdd;
    }
};
