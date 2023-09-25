#include <vector>
#include <unordered_map>
using namespace std;

// runtime: O(n) but faster than 2.cc
// space: O(1) maps has limited slots

// 3.cc is similar to 2.cc except that it will check the map along the way when
// constructing it


// the default value of 0 when adding a new key to a map will make all test
// cases whose solutions contain 1st element in nums failed

// to deal with that, I added 1 when storing the index on line 29, and subtract
// it again when returning on line 28

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        // O(n)
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];

            if (map[remain] != 0) {
                return vector<int> {i, map[remain] - 1};
            } else map[nums[i]] = i + 1; 
        }

        return vector<int> {0, 0};
    }
};