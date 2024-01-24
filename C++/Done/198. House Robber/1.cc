#include <vector>
using namespace std;

// approach: recursion
// time: too slow
// space:


class Solution {
public:
    int rob(vector<int>& nums) {
        int maxSum = nums[0];
        
        maxSum = max(maxSum, rec(0, nums[0], nums));

        if (nums.size() > 1) maxSum = max(maxSum, rec(1, nums[1], nums));

        return maxSum;
    }

    int rec(int addIndex, int curSum, vector<int>& nums) {
        int maxSum = curSum;
        
        for (int i = addIndex + 2; i < nums.size(); i++) {
            maxSum = max(maxSum, rec(i, curSum + nums[i], nums));
        }

        return maxSum;
    }
};