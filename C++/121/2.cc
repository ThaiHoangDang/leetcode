#include <vector>
using namespace std;

// runtime: O(n^2)
// space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minSoFar = prices[0];

        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices.at(i) <= minSoFar) {
                minSoFar = prices.at(i);

                for (int j = i + 1; j < prices.size(); j++) {
                    if (prices.at(j) - prices.at(i) > maxProfit) maxProfit = 
                            prices.at(j) - prices.at(i);
                }
            }
        }

        return maxProfit;
    }
};