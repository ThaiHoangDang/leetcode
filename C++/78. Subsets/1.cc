#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    void findSubsets(vector<int> nums, vector<vector<int>> &answer) {
        answer.emplace_back(nums);

        for (int i = 0; i < nums.size(); i++) {
            
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;

        findSubsets(nums, answer);

        return answer;        
    }
};