#include <vector>
using namespace std;

// runtime: O(n^2)
// space: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int> {0, 0};
    }
};