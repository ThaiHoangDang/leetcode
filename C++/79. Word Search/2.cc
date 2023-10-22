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

    }
};
