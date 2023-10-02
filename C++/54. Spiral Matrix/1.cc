#include <vector>
using namespace std;

// time: O(n)
// space: O(1)


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;

        int top = 0, bottom = 0, left = 0, right = 0, 
            direction = 0, size = matrix.size() * matrix[0].size();

        while (result.size() < size) {

            switch (direction) {
                case 0:
                    for (int i = left; i < matrix[0].size() - right; i++) result.push_back(matrix[top][i]);
                    top++; direction = 1; break;
                case 1:
                    for (int i = top; i < matrix.size() - bottom; i++) result.push_back(matrix[i][matrix[0].size() - 1 - right]);
                    right++; direction = 2; break;
                case 2:
                    for (int i = right; i < matrix[0].size() - left; i++) result.push_back(matrix[matrix.size() - 1 - bottom][matrix[0].size() -1 - i]);
                    bottom++; direction = 3; break;
                case 3:
                    for (int i = bottom; i < matrix.size() - top; i++) result.push_back(matrix[matrix.size() - 1 - i][left]);
                    left++; direction = 0; break;
                }
        }

        return result;
    }
};