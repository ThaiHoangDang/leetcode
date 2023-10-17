#include <vector>
using namespace std;

// approach: keep track of rows and cols that have 0
// time: O(mn)
// space: O(n + m)


class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> rowZero (matrix.size(), 0), colZero (matrix[0].size(), 0);

        // find rows and cols that contain 0
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = 1; colZero[j] = 1;
                }
            }
        }

        // update rows that have 0
        for (int i = 0; i < rowZero.size(); i++) {
            if (rowZero[i] == 1) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // update cols that have 0
        for (int i = 0; i < colZero.size(); i++) {
            if (colZero[i] == 1) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
