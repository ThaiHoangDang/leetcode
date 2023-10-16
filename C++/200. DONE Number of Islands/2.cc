#include <vector>
#include <deque>
using namespace std;

// approach: DFS
// time:
// space:


void expand(int x, int y, vector<vector<char>> &grid) {
    deque<vector<int>> queue {vector<int>{x, y}};
    int tempX, tempY;

    while (! queue.empty()) {
        tempX = queue.front()[0]; tempY = queue.front()[1];
        queue.pop_front(); grid[tempY][tempX] = '2';

        if (tempY - 1 >= 0 && grid[tempY - 1][tempX] == '1') queue.emplace_back(vector<int> {tempX, tempY - 1});

        if (tempY + 1 < grid.size() && grid[tempY + 1][tempX] == '1') queue.emplace_back(vector<int> {tempX, tempY + 1});

        if (tempX - 1 >= 0 && grid[tempY][tempX - 1] == '1') queue.emplace_back(vector<int> {tempX - 1, tempY});

        if (tempX + 1 < grid[0].size() && grid[tempY][tempX + 1] == '1') queue.emplace_back(vector<int> {tempX + 1, tempY});
    }
}

class Solution {

    public:
        int numIslands(vector<vector<char>>& grid) {
            int numIslands = 0;

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == '1') { expand(j, i, grid); numIslands++; }
                }
            }

            return numIslands;
        }
};
