#include <vector>
using namespace std;

// approach: DFS
// time:
// space:


void expand(int x, int y, vector<vector<char>> &grid) {
    vector<vector<int>> stack {vector<int>{x, y}};
    int tempX, tempY;

    while (! stack.empty()) {
        tempX = stack.back()[0]; tempY = stack.back()[1];
        stack.pop_back(); grid[tempY][tempX] = '2';

        if (tempY - 1 >= 0 && grid[tempY - 1][tempX] == '1') stack.emplace_back(vector<int> {tempX, tempY - 1});

        if (tempY + 1 < grid.size() && grid[tempY + 1][tempX] == '1') stack.emplace_back(vector<int> {tempX, tempY + 1});

        if (tempX - 1 >= 0 && grid[tempY][tempX - 1] == '1') stack.emplace_back(vector<int> {tempX - 1, tempY});

        if (tempX + 1 < grid[0].size() && grid[tempY][tempX + 1] == '1') stack.emplace_back(vector<int> {tempX + 1, tempY});
    }
}

class Solution {

    public:
        int numIslands(vector<vector<char>>& grid) {
            int numIslands = 0;
            int row = grid.size(), col = grid[0].size();

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == '1') { expand(j, i, grid); numIslands++; }
                }
            }

            return numIslands;
        }
};
