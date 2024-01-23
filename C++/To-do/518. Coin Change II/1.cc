#include <vector>
using namespace std;

// time: O(mn)
// space: O(n)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> minByAmount(amount + 1, -1); minByAmount[0] = 0;
        int tempMin = 0, answer = 0;

        // bottom up 
        for (int i = 1; i <= amount; i++) {
            
            // keep track of min coins used
            tempMin = amount + 1; 

            // go through each coin
            for (int j = 0; j < coins.size(); j++) {
                
                // if that coin can combine with a smaller problem
                if (i - coins[j] >= 0 && minByAmount[i - coins[j]] != -1) {
                    tempMin = min(tempMin, 1 + minByAmount[i - coins[j]]);

                    if (i == amount) {
                      answer += change(i - coins[j], coins);
                    }
                }
            }

            // update min coins used for a particular amount
            if (tempMin != amount + 1) {
                minByAmount[i] = tempMin;
            }
        }

        return answer;
    }
};