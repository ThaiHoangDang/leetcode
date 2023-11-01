#include <vector>
#include <cmath>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        if (rectangles.size() == 0) return true;

        int left = rectangles[0][0], right = left, bottom = left, top = left, numBlocks = 0;

        // find borders
        for (int i = 0; i < rectangles.size(); i++) {
            left = min(left, rectangles[i][0]);
            bottom = min(bottom, rectangles[i][1]);
            right = max(right, rectangles[i][2]);
            top = max(top, rectangles[i][3]);

            numBlocks += ((rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]));
        }

        if (numBlocks != (right - left) * (top - bottom)) return false;

        vector<bool> matrix ((right - left) * (top - bottom));

        for (int i = 0; i < rectangles.size(); i++) {
            
            for (int j = 0; j < rectangles[i][3] - rectangles[i][1]; j++) {
                for (int k = 0; k < rectangles[i][2] - rectangles[i][0]; k++) {
                    if (matrix[(top - rectangles[i][3] + j) * (right - left) + rectangles[i][0] - left + k] == false) {
                        matrix[(top - rectangles[i][3] + j) * (right - left) + rectangles[i][0] - left + k] = true;
                    } else return false;
                }
            }
        }

        // return false if there is a missing block
        for (const auto &i : matrix) if (i == false) return false;

        return true;
    }
};
