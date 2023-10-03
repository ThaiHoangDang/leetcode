#include <vector>
using namespace std;

// time: O(n)
// space: O(1)


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        // transpose
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                swap(matrix[i][j], matrix[size - 1 - j][size - 1 - i]);
            }
        }

        // rotate
        for (int i = 0; i < size / 2; i++) {
            for (int j = 0; j < size; j++) {
                swap(matrix[i][j], matrix[size - 1 - i][j]);
            }
        }
    }
};

// 1: 0-0 -> 2-2
// 2: 0-1 -> 1-2
// 3: 0-2 -> 0-2
// 4: 1-0 -> 2-1


// 1: 0-1 -> 2-3