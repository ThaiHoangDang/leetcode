#include <vector>
using namespace std;

// Doesn't work..
// time: 
// space:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSoFar = 0, left = 0, right = height.size() - 1, maxLeft = 0,  maxRight = 0;
        bool leftTurn = true;

        while (left < right) {
            
            if (leftTurn) {
                if (left != 0 && maxLeft > height[left]) { left++; continue; }
                else maxLeft = height[left];
            } else {
                if (right != height.size() - 1 && maxRight > height[right]) { right--; continue; }
                else maxRight = height[right];
            }

            maxSoFar = max(maxSoFar, min(height[left], height[right]) * (right - left));
            
            if (leftTurn) left++;
            else right--;

            leftTurn = ! leftTurn;
        }

        return maxSoFar;
    }
};
