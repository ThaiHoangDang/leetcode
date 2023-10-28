#include <vector>
using namespace std;

// approach: BFS
// time: O(n)
// space: O(n)


class Solution {

    public:
        void expand(int x, int y, vector<vector<char>> &grid) {

            // check if the coordinates are valid
            if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size() && grid[y][x] == '1') {

                grid[y][x] = '2'; // marking as visited

                expand(x, y - 1, grid); // up
                expand(x, y + 1, grid); // down
                expand(x - 1, y, grid); // left
                expand(x + 1, y, grid); // right
            }
        }

        int numIslands(vector<vector<char>>& grid) {
            int numIslands = 0;
            int row = grid.size(), col = grid[0].size();

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    // perform BFS
                    if (grid[i][j] == '1') { expand(j, i, grid); numIslands++; }
                }
            }

            return numIslands;
        }
};