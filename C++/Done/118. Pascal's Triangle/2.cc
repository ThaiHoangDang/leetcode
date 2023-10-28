#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            result.emplace_back(vector<int>());

            result.back().emplace_back(1);

            for (int j = 1; j < i; j++) result.back().emplace_back(result[result.size() - 2][j - 1] + result[result.size() - 2][j]);

            if (i != 0) result.back().emplace_back(1);
        }

        return result;
    }
};
