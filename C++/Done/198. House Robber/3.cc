#include <vector>
using namespace std;

// approach: dynamic programming
// time: O(n) beat 100% :D
// space: O(1)


class Solution {
public:
    int rob(vector<int>& nums) {
        
		vector<int> tracker (3, 0);

        // return early for special case
        if (nums.size() == 1) return nums[0];

		for (int i = 0; i < nums.size(); i++) {

			if (i == 0) tracker[0] = nums[0];
			else if (i == 1) tracker[1] = max(nums[0], nums[1]);
			else {
				tracker[2] = max(tracker[0] + nums[i], tracker[1]);

				tracker[0] = tracker[1];
				tracker[1] = tracker[2];
			}
		}

		return tracker[1];
    }
};