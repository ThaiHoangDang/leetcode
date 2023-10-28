#include <vector>
#include <unordered_map>
using namespace std;

// runtime: O(n)
// space: O(1) maps has limited slots

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        
        // O(n)
        for (int i = 0; i < nums.size(); i++) {
            maps[nums.at(i)] = i; 
        }

        // O(n)
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];

            if (maps[remain] != 0 && maps[remain] != i) {
                return vector<int> {i, maps.at(remain)};
            }
        }

        return vector<int> {0, 0};
    }
};