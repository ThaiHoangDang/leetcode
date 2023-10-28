#include <vector>
#include <string>
using namespace std;

// time:
// space:


bool notIn(int x, int y, vector<vector<int>> &item) {
    for (auto i : item) {
        if (i[0] == x && i[1] == y) return false;
    }

    return true;
}

bool recSearch(int x, int y, vector<vector<int>> items, vector<vector<char>>& board, string word) {

    if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size() && notIn(x, y, items) && board[y][x] == word[items.size()]) {
        items.emplace_back(vector<int> {x, y});

        if (items.size() == word.length()) return true;

        return recSearch(x + 1, y, items, board, word) ||
                recSearch(x - 1, y, items, board, word) ||
                recSearch(x, y + 1, items, board, word) ||
                recSearch(x, y - 1, items, board, word);
    }

    return false;
}

class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {

        // add the starting points
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) 
                    if (recSearch(j, i, vector<vector<int>> {{}}, board, word)) return true;
            }
        }

        return false;
    }
};
