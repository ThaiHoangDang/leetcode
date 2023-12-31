#include <vector>;
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums.at(mid) == target) {
                return mid;
            } else if (nums.at(mid) < target) {
                left = mid + 1;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            }
        }

        return -1;
    }
};