#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// time: O(n.sqrt(n))
// space: O(n)

class Solution {
public:
    // check if n a perfect square
    bool isPerfectSquare(int n) {
        int temp = sqrt(n);
        return temp * temp == n;
    }


    int numSquares(int n) {
        
        // return early if n is a perfect square
        if (isPerfectSquare(n)) return 1;

        // keep track of result for smaller inputs
        vector<int> minByN (n + 1, -1); minByN[0] = 0;
        int tempMin;

        // go through smaller inputs, bottom up
        for (int i = 1; i <= n; i++) {
            
            // keep track of best result
            tempMin = i + 1;
            
            // go though perfect square from small to large
            for (int j = 1; j <= sqrt(i); j++) {
                
                // update tempMin with smaller answer
                tempMin = min(tempMin, 1 + minByN[i - j * j]);
            }

            // set result for corresponding input
            minByN[i] = tempMin;
        }

        return minByN.back();
    }
};
