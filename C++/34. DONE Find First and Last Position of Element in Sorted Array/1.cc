#include <vector>
using namespace std;

// approach: binary search
// time: O(logn)
// space: O(1)


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid, spreadLeft, spreadRight;
        bool found = false;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else { found = true; break; }
        }

        if (found) {
            spreadRight = mid; spreadLeft = mid;

            while (spreadRight + 1 < nums.size() && nums[spreadRight + 1] == target) spreadRight++;
            while (spreadLeft - 1 >= 0 && nums[spreadLeft - 1] == target) spreadLeft--;

            return vector<int> {spreadLeft, spreadRight};
        } else return vector<int> {-1, -1};
    }
};
