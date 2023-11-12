#include <vector>
using namespace std;

// time: O(n^2), faster
// space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSoFar = 0, curMaxHeight;

        for (int i = 0; i < height.size() - 1; i++) {

            if (i != 0 && curMaxHeight > height[i]) continue;
            else curMaxHeight = height[i];

            for (int j = i + 1; j < height.size(); j++) maxSoFar = max(maxSoFar, min(height[i], height[j]) * (j - i));
        }

        return maxSoFar;
    }
};
