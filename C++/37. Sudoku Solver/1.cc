#include <vector>
using namespace std;

// time:
// space: 

class Solution {
public:
    bool check(int x, int y, vector<vector<char>>& board) {
        int stepX = x / 3, stepY = y / 3;

        // check horizontally
        for (int i = 0; i < board.size(); i++) {
            if (i != x && board[y][i] == board[y][x]) return false;
        }

        // check vertically
        for (int i = 0; i < board.size(); i++) {
            if (i != y && board[i][x] == board[y][x]) return false;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
    }
};