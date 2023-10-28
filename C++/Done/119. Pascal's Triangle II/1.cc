#include <vector>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp1, temp2;

        for (int i = 0; i < rowIndex + 1; i++) {
            temp2.emplace_back(1);

            for (int j = 1; j < i; j++) temp2.emplace_back(temp1[j - 1] + temp1[j]);

            if (i != 0) temp2.emplace_back(1);

            swap(temp1, temp2); temp2.clear();
        }

        return temp1;
    }
};
