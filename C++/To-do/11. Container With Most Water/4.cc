#include <vector>
using namespace std;

// time: 
// space:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSoFar = 0, left = 0, right = height.size() - 1, maxLeft = 0,  maxRight = height.size() - 1;
        bool leftTurn = true;

        while (left < right) {

            maxSoFar = max(maxSoFar, min(height[maxLeft], height[maxRight]) * (maxRight - maxLeft));
            
            if (leftTurn) {
                if (height[maxLeft] < height[left]) maxLeft = left;

                left++;
            } else {
                if (height[maxRight] < height[right]) maxRight = right;

                right--;
            }            
          
            leftTurn = ! leftTurn;
        }
        maxSoFar = max(maxSoFar, min(height[maxLeft], height[maxRight]) * (maxRight - maxLeft));

        cout << maxLeft << endl;
        cout << maxRight << endl;


        return maxSoFar;
    }
};
