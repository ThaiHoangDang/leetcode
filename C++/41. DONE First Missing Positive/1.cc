#include <vector>
using namespace std;

// time: O(n)
// space: O(1)


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int result = nums.size();

        if (nums.size() == 1 && nums[0] == 1) return 2;
        
        for (int i = 0; i < nums.size(); ) {
            
            if (nums[i] == i) { // num at correct position already
                i++;
            } else if (nums[i] >= 0 && nums[i] < nums.size()) { // num needs to be moved
                if (nums[nums[i]] == nums[i]) nums[nums[i]] = -1; // avoid duplicates
                swap(nums[i], nums[nums[i]]);
            } else if (nums[i] == result) { // 
                result++; 
            } else { // negagive or out of range
                nums[i] = -1; i++;
            }
        }

        // find the smallest
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return result;
    }
};
