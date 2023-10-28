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
            vector<int> holder;

            holder.emplace_back(1);

            for (int j = 1; j < i; j++) holder.emplace_back(result.back()[j - 1] + result.back()[j]);

            if (i != 0) holder.emplace_back(1);

            result.emplace_back(holder);
        }

        return result;
    }
};
