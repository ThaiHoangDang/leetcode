#include <vector>
#include <string>
using namespace std;

// time:
// space:

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> answer;
        vector<int> temp;

        if (m * n != original.size()) return answer;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                temp.emplace_back(original[i * n + j]);
            }
            answer.emplace_back(temp);
            temp.clear();
        }

        return answer;
    }
};
