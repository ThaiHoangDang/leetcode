#include <vector>
using namespace std;

// space: O(n ^ 2) too slow, check 2.cc for faster approach
// time: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int target;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) target = nums[i];
            }
        }

        return target;
    }
};