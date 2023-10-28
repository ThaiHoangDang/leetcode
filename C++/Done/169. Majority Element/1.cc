#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> holder;
        int result;
        
        for (auto num : nums) holder[num]++;

        for (auto element : holder) {
            if (element.second > nums.size() / 2) {
                result = element.first; break;
            }
        }

        return result;
    }
};
