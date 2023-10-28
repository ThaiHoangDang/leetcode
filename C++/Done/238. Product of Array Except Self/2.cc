#include <vector>
using namespace std;

// time: O(n)
// space: O(1) use the output array to store values along the way

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        result.emplace_back(1);

        for (int i = 0; i < nums.size() - 1; i++) result.emplace_back(result.at(i) * nums.at(i));

        int product = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            product *= nums.at(nums.size() - 1 - i);

            result.at(nums.size() - 2 - i) *= product;
        }

        return result;
    }
};

// 1 2 3 4
// 24 12 8 6

// 1 1 2 6
// 1 4 12 24