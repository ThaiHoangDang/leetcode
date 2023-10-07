#include <vector>
#include <string>
using namespace std;

// time:
// space:

bool notIn(int x, int y, vector<vector<int>> item) {
    for (auto i : item) {
        if (i[0] == x && i[1] == y) return false;
    }

    return true;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<vector<int>>> stack;
        int lastX, lastY;

        // add the starting points
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) stack.emplace_back(vector<vector<int>> {{j, i}});
            }
        }

        // using dfs to search for word
        while (! stack.empty()) {
            vector<vector<int>> item = stack.back(); stack.pop_back();

            if (item.size() == word.length()) return true;

            lastX = item.back()[0]; lastY = item.back()[1];

            if ((lastY - 1 >= 0) && notIn(lastX, lastY - 1, item) && 
                    board[lastY - 1][lastX] == word[item.size()]) {
                vector<vector<int>> newItem = item;
                newItem.emplace_back(vector<int> {lastX, lastY - 1});
                stack.emplace_back(newItem);
            }

            if ((lastY + 1 < board.size()) && notIn(lastX, lastY + 1, item) && 
                    board[lastY + 1][lastX] == word[item.size()]) {
                vector<vector<int>> newItem = item;
                newItem.emplace_back(vector<int> {lastX, lastY + 1});
                stack.emplace_back(newItem);
            }

            if ((lastX - 1 >= 0) && notIn(lastX - 1, lastY, item) && 
                    board[lastY][lastX - 1] == word[item.size()]) {
                vector<vector<int>> newItem = item;
                newItem.emplace_back(vector<int> {lastX - 1, lastY});
                stack.emplace_back(newItem);
            }

            if ((lastX + 1 < board[0].size()) && notIn(lastX + 1, lastY, item) && 
                    board[lastY][lastX + 1] == word[item.size()]) {
                vector<vector<int>> newItem = item;
                newItem.emplace_back(vector<int> {lastX + 1, lastY});
                stack.emplace_back(newItem);
            }
        }

        return false;
    }
};

C A A
A A A
B C D
