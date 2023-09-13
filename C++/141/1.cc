#include <vector>
using namespace std;

// runtime: O(n^2)
// space: O(n)


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode *>addressList;

        while (head) {
            for (auto i : addressList) {
                if (i == head) return true;
            }

            addressList.emplace_back(head);
            head = head->next;
        }

        return false;
    }
};