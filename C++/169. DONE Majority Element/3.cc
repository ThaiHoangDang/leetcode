#include <vector>
#include <unordered_map>
using namespace std;

// time: O(nlog(n))
// space: O(1)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int result, track = nums[0], length = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == track) length++;
            else {
                if (length > nums.size() / 2) {
                    result = track;
                    break;
                }
                track = nums[i];
                length = 1;
            }
        }

        return result;
    }
};
