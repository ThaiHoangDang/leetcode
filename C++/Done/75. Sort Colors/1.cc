#include <vector>
using namespace std;

// arroach: array traversing
// runtime: O(n), beats 100%
// space: O(1)


class Solution {
public:
    void sortColors(vector<int>& nums) {
        // keeps track of swapping place
        int tracker = 0; 
        
        // put all 0s to front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[tracker], nums[i]);
                tracker++;
            }
        }

        // put all 1s to front (after 0s)
        for (int i = tracker; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[tracker], nums[i]);
                tracker++;
            }
        }   
    }
};
