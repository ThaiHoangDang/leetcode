#include <vector>
#include <iostream>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    int trap(vector<int>& height) {
        int totalAmount = 0, maxLeft, maxRight;

        for (int i = 1; i < height.size() - 1; i++) {
            
            maxLeft = 0; maxRight = 0;

            for (int j = 0; j < i; j++) { maxLeft = max(maxLeft, height[j]); } 

            if (maxLeft <= height[i]) continue;

            for (int j = i + 1; j < height.size(); j++) { maxRight = max(maxRight, height[j]); }

            if (maxRight <= height[i]) continue;
            
            totalAmount += min(maxLeft, maxRight) - height[i];

        }

        return totalAmount;
    }
};
