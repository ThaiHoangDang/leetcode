#include <vector>

using namespace std;

class NumArray {
    vector<int> sums;

public:
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            sums.emplace_back(i == 0 ? nums.at(0) : sums.at(i - 1) + nums.at(i));
        }
    }
    
    int sumRange(int left, int right) {
        return sums.at(right) - ((left == 0) ? 0 : sums.at(left - 1));
    }
};
