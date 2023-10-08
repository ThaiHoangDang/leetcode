#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n), better than 1.cc
// space: O(n)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> holder;
        int result;
        
        for (auto num : nums) {
            holder[num]++;

            if (holder[num] > nums.size() / 2) {
                result = num; break;
            }
        }

        return result;
    }
};
