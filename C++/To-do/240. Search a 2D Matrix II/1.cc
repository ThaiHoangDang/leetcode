#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1, mid1, mid2;

        while (left <= right) {
            mid1 = (left + right) / 2;

            if (matrix.back()[mid1] < target) left = mid1 + 1;
            else if (matrix[0][mid1] > target) right = mid1 - 1;
            else break;
        }

        if (right < 0) return false;

        while (top <= bottom) {
            mid2 = (top + bottom) / 2;

            if (matrix[mid2][mid1] < target) top = mid2 + 1;
            else if (matrix[mid2][mid1] > target) bottom = mid2 - 1;
            else return true;
        }

        return false;
    }
};
