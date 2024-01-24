#include <vector>
using namespace std;

// approach: dynamic programming
// time: O(n) beat 100% :D
// space: O(n), not efficient


class Solution {
public:
    int rob(vector<int>& nums) {

		vector<int> maxByEachPoint (nums.size(), 0);

		for (int i = 0; i < nums.size(); i++) {

			if (i == 0) maxByEachPoint[i] = nums[i];
			else if (i == 1) maxByEachPoint[i] = max(nums[0], nums[1]);
			else {
				maxByEachPoint[i] = max(maxByEachPoint[i - 2] + nums[i], maxByEachPoint[i - 1]);
			}
		}

		return maxByEachPoint.back();
    }
};