#include <vector>
using namespace std;

// runtime:
// space:

bool compare(vector<int> &a, vector<int> &b) {
    if (a.at(1) == b.at(1)) return a.at(0) < b.at(0);

    return a.at(1) < b.at(1);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> pricesWithOrder;
        int curMax = 0;

        for (int i = 0; i < prices.size(); i++) pricesWithOrder.emplace_back(vector {i, prices.at(i)});

        sort(pricesWithOrder.begin(), pricesWithOrder.end(), compare);

        for (int i = 0; i < prices.size(); i++) {
            for (int j = prices.size() - 1; j > i; j--) {
                if (pricesWithOrder.at(i).at(1) == pricesWithOrder.at(j).at(1)) break;

                if (pricesWithOrder.at(i).at(0) < pricesWithOrder.at(j).at(0)) {
                    curMax = (pricesWithOrder.at(j).at(1) - pricesWithOrder.at(i).at(1) > curMax) ? pricesWithOrder.at(j).at(1) - pricesWithOrder.at(i).at(1) : curMax;
                    break;
                }
            }
        }

        return curMax;
    }
};