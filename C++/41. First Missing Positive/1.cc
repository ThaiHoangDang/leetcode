#include <vector>
using namespace std;

// time:
// space:


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int left = 1, right, max;

        for (auto num : nums) if (num > max) max = num; 
        
        right = max;

        for (auto num : nums) {
            if (num > left && num < right) left = num;
        }
    }
};