#include <vector>
#include <deque>
using namespace std;

// approach: max reach
// time: O(n)
// space: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            if (i > maxReach) return false;
            if (maxReach >= nums.size() - 1) return true;

            maxReach = max(maxReach, nums[i] + i);
        }

        return false;
    }
};
