#include <vector>

using namespace std;

class NumArray {
    vector<int> nums;

public:
    NumArray(vector<int>& nums): nums {move(nums)} {}
    
    int sumRange(int left, int right) {
        int sum = 0;
        
        for (int i = left; i <= right; i++) {
            sum += nums.at(i);
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */