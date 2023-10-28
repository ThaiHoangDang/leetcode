#include <vector>
#include <deque>
using namespace std;

// approach: Dynamic Programming
// time: O(n^2)
// space: O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        deque<int> table; table.emplace_back(nums.size() - 1);
        int item;

        while (! table.empty()) {
            item = table.front(); table.pop_front();

            if (item == 0) return true;

            for (int i = 0; i < item; i++) {
                if (nums[i] >= 0 && i + nums[i] >= item) table.emplace_back(i);
            }

            nums[item] = -nums[item];
        }

        return false;
    }
};
