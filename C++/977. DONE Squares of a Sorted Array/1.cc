#include <vector>
#include <cmath>
using namespace std;

// time:
// space:

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result;
        int left = -1, right = -1;

        if (nums.size() == 0) return result;
        else if (nums.size() == 1) {
            result.emplace_back(nums[0] * nums[0]); return result;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < 0 && nums[i + 1] >= 0) {
                left = i; right = i + 1; break;
            }
        }

        if (left == right) {
            if (nums[0] >= 0) {
                right = 0;
            } else {
                left = nums.size() - 1; right = nums.size();
            }
        }

        while (result.size() < nums.size()) {
            if (right < nums.size() && ((left < 0) || (abs(nums[left]) > abs(nums[right])))) {
                result.emplace_back(nums[right] * nums[right]);
                right++;
            } else {
                result.emplace_back(nums[left] * nums[left]);
                left--;
            }
        }

        return result;
    }
};