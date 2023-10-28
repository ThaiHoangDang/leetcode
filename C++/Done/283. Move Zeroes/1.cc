#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};