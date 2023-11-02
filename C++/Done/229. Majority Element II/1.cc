#include <vector>
#include <cmath>
using namespace std;

// approach: sorting, array traverse
// time: O(nlog(n))
// space: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        sort(nums.begin(), nums.end());

        int curNum = nums[0], times = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curNum) {
                times++; 
            } else {
                if (times > floor(nums.size() / 3)) result.emplace_back(curNum);
                curNum = nums[i]; times = 1;
            }
        }

        if (times > floor(nums.size() / 3)) result.emplace_back(curNum);

        return result;
    }
};
