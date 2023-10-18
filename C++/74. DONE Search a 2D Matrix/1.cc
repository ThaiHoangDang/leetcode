#include <vector>
using namespace std;

// approach: Similar like binary search for 1D array
// time: O(log(mn))
// space: O(1)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0, right = matrix.size() * matrix[0].size() - 1, mid, x, y;

        while (left <= right) {
            mid = (left + right) / 2; 
            y = mid / matrix[0].size(); 
            x = mid - y * matrix[0].size();

            if (matrix[y][x] > target) {
                right = mid - 1;
            } else if (matrix[y][x] < target) {
                left = mid + 1;
            } else return true;
        }

        return false;
    }
};
