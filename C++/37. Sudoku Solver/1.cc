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

        // check box
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((stepY * 3 + i != y || stepX * 3 + j != x) && board[stepY * 3 + i][stepX * 3 + j] == board[y][x]) return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; y < board.size(); x++) {

                if (board[y][x] == '.') {
                                        
                }
            }
        }
    }
};