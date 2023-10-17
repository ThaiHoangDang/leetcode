#include <vector>
using namespace std;

// approach: keep track using row 0 and col 0
// time: O(mn)
// space: O(1)


class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        bool row0has0 = false, col0has0 = false;

        // check if row 0 contains 0
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) { row0has0 = true; break; }
        }

        // check if col 0 contains 0
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) { col0has0 = true; break; }
        }

        // traverse the matrix and update row 0 and col 0 based on the 
        // indexes that have 0
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; matrix[i][0] = 0;
                }
            }
        }

        // traverse the matrix and update its cells
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }

        // update row 0 and col 0
        if (row0has0) for (int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
        if (col0has0) for (int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
};
