#include <vector>
using namespace std;

// approach: dynamic programming, cell(x, y) = cell(x - 1, y) + cell(x, y - 1)
// time: O(m * n)
// space: O(n), instead of generting the whole table, 
//        I only need two rows and keep updating them simutaniously
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> first(n), second(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i == 0 || j == 0) first[j] = 1;
                else first[j] = first[j - 1] + second[j];
            }
            swap(first, second);
        }
        
        return second.back();
    }
};
