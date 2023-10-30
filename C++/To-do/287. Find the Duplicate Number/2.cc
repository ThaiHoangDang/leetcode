#include <vector>
using namespace std;

// space: 
// time: 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int target, index1 = nums[0], index2 = nums[0];
        
        while (true) {
            index1 = nums[index1];
            index2 = nums[nums[index2]];

            if (index1 == index2) break;
        }

        index1 = nums[0];

        while (true) {
            index1 = nums[index1];
            index2 = nums[index2];

            if (index1 == index2) break;
        }

        return index1;
    }
};

1 2 3 4 6 2 5

index1: 2 3 4 6 (5) 2 3 4 6 (5)
index2: 2-3 4-6 5-2 3-4 6-(5) 2-3 4-6 5-2 3-4 6-(5)

