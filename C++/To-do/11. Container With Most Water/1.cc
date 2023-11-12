#include <vector>
using namespace std;

// time: O(n^2) too slow
// space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSoFar = 0;

        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {

                maxSoFar = max(maxSoFar, min(height[i], height[j]) * (j - i));
            }
        }

        return maxSoFar;
    }
};
