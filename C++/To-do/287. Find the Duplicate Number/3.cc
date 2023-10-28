#include <vector>
using namespace std;

// THIS APPROACH IS WRONG SINCE WE ARE NOT ALLOWED TO MODIFY THE ARRAY
// space: O(n)
// time: O(1)


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result;

        for (int i = 0; i < nums.size(); ) {
            
            if (nums[i] == i + 1) i++;
            else if (nums[nums[i] - 1] == nums[i]) { result = nums[i]; break; }
            else swap(nums[nums[i] - 1], nums[i]);
        }

        return result;
    }
};

// [1,3,4,2,2]
// [1,3,4,2,2]
// [1,4,3,2,2]
// [1,2,3,4,2]
// [1,2,3,4,2]
