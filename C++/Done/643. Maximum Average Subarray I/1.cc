#include <vector>
using namespace std;

// time:
// space

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0, sum = 0;

        for (int i = 0; i < k; i++) sum+= nums[i];

        maxSum = sum;

        for (int i = 1; i < nums.size() - k + 1; i++) {
            sum = sum - nums[i - 1] + nums[i + k - 1]; 
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};
