#include <vector>
#include <algorithm>
using namespace std;

// approach: BFS
// time: O(n)
// space: O(n)

class Solution {
public:

    int expand(int x, int y, vector<vector<int>> &grid) {

        // check if the coordinates are valid
        if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size() && grid[y][x] == 1) {

            grid[y][x] = 2; // marking as visited

            return 1 + expand(x, y - 1, grid) + expand(x, y + 1, grid) + 
                expand(x + 1, y, grid) + expand(x - 1, y, grid);
        }

        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int biggestIsland = 0;
        int row = grid.size(), col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // perform BFS
                if (grid[i][j] == 1) { biggestIsland = max(biggestIsland, expand(j, i, grid)); }
            }
        }

        return biggestIsland;
    }
};