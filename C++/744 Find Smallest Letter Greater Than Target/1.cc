#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, index = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (letters.at(mid) <= target) {
                left = mid + 1;
            } else if (letters.at(mid) > target) {
                right = mid - 1;
            }
        }

        if (left > letters.size() - 1 || right < 0) return letters.at(0);
        else return letters.at(left);
    }
};