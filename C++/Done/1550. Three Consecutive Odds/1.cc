#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

      int oddCount = 0;

      for (int i = 0; i < arr.size(); i++)
        if (oddCount == 2 && arr[i] % 2 == 1) return true;
        else if (arr[i] % 2 == 1) oddCount++;
        else if (arr[i] % 2 == 0) oddCount = 0;

      return false;
    }
};
