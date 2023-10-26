#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1, midX, midY;

        while (left <= right || top <= bottom) {
            midX = (left + right) / 2; midY = (top + bottom) / 2;

            if () {
                
            }
        }

        return false;
    }
};
