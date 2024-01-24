#include <vector>
using namespace std;

// approach: Backtracking, Recursive
// time: 
// space: 


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());
        rec(0, vector<int>{}, nums, answer);

        return answer;        
    }

        void rec(int addIndex, vector<int> cur, vector<int>& nums, vector<vector<int>> & answer) {
        
        if (addIndex < nums.size()) {
            
            // take new num
            vector<int> temp = cur; temp.emplace_back(nums[addIndex]);

            if (addIndex == nums.size() - 1) {

                if (notIn(cur, answer)) answer.emplace_back(cur);
                if (notIn(temp, answer)) answer.emplace_back(temp);
            }
            
            rec(addIndex + 1, cur, nums, answer);
            rec(addIndex + 1, temp, nums, answer);
        }
    }

    bool notIn(vector<int> &val, vector<vector<int>> & answer) {

        for (int i = answer.size() - 1; i >= 0; i--) {

            if (answer[i] == val) return false;
        }

        return true;
    }
};
