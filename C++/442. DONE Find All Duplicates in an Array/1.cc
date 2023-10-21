#include <vector>
using namespace std;

// approach: Array traversing, move numbers to their correct position based on their values
// time: O(n)
// space: O(1)


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ) {

            if (nums[i] == i + 1) i++;
            else if (nums[nums[i] - 1] == nums[i]) {
                result.emplace_back(nums[i]);
                nums[i] = -1; i++;
            } else swap(nums[i], nums[nums[i] - 1]);
        }

        return result;
    }
};

// [4,3,2,7,8,2,3,1]
// [7,3,2,4,8,2,3,1]
// [3,3,2,4,8,2,7,1]
// [2,3,3,4,8,2,7,1]
// [3,2,3,4,8,2,7,1]
// [-1,3,2,4,8,2,7,1]
// [-1,2,3,4,8,2,7,1]
// [-1,2,3,4,1,2,7,8]
// [1,2,3,4,-1,-1,7,8]