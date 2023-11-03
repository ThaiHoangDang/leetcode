#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; answer.emplace_back(vector<int>{});
        vector<int> holder;

        for (int i = 0; i < nums.size(); i++) {
            answer.emplace_back(vector<int>{nums[i]});
            
        }

        return answer;        
    }
};