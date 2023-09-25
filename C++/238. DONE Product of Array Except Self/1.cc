#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right, result;

        left.emplace_back(1);
        right.emplace_back(1);

        for (int i = 0; i < nums.size() - 1; i++) left.emplace_back(left.at(i) * nums.at(i));
        for (int i = 0; i < nums.size() - 1; i++) right.emplace_back(right.at(i) * nums.at(nums.size() - 1 - i));

        for (int i = 0; i < nums.size(); i++) result.emplace_back(left.at(i) * right.at(nums.size() - 1 - i));

        return result;
    }
};

// 1 2 3 4
// 24 12 8 6

// 1 1 2 6
// 1 4 12 24