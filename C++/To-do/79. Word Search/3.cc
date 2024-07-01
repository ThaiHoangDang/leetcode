#include <vector>
#include <string>
using namespace std;

// time:
// space:

#define VISITED '#'

class Solution {
public:
    bool recSearch(int x, int y, int size, vector<vector<char>>& board, string word) {
        if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size() 
            && board[y][x] != VISITED && board[y][x] == word[size]) {

            board[y][x] = VISITED; // Mark as visited

            if (size == word.length()) return true;

            if (!recSearch(x + 1, y, size + 1, board, word) &&
                !recSearch(x - 1, y, size + 1, board, word) &&
                !recSearch(x, y + 1, size + 1, board, word) &&
                !recSearch(x, y - 1, size + 1, board, word)) return false;

            board[y][x] = word[size]; // Reset visited cell for further exploration

            return true;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // ... rest of the code ...
        
        // Reset visited cells after successful search
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == VISITED) {
                    board[i][j] = word[0]; // Assuming word starts with the same character used for visited cells
                }
            }
        }
        
        return false;
    }


};

