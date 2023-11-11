#include <vector>
#include <iostream>
using namespace std;

// approach: 
// time: O(n)
// space: O(n)


class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int totalAmount = 0;
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 1; i < n - 1; ++i) {
            int minSide = min(maxLeft[i], maxRight[i]);
            if (minSide > height[i]) {
                totalAmount += minSide - height[i];
            }
        }

        return totalAmount;
    }
};
