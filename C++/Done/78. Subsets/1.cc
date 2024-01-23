#include <vector>
using namespace std;

// approach: Backtracking, Recursive
// time: n . 2^n
// space: 2^n


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;

        rec(0, vector<int>{}, nums, answer);

        return answer;        
    }

    void rec(int addIndex, vector<int> cur, vector<int>& nums, vector<vector<int>> & answer) {
        
        if (addIndex < nums.size()) {
            
            // take new num
            vector<int> temp = cur; temp.emplace_back(nums[addIndex]);

            if (addIndex == nums.size() - 1) {
                answer.emplace_back(cur);
                answer.emplace_back(temp);
            }
            
            rec(addIndex + 1, cur, nums, answer);
            rec(addIndex + 1, temp, nums, answer);
        }
    }
};
