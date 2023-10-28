#include <vector>
using namespace std;

// runtime: O(n)
// space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left, right, profit;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < prices[left]) left = i;
            else if (prices[i] - prices[left] > profit) {
                profit = prices[i] - prices[left];
                right = i;
            }
        }

        return profit;
    }
};
