#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool isPalindrome(int x) {
        string input = to_string(x);

        for (int i = 0; i < input.length() / 2; i++) {
            if (input[i] != input[input.length() - 1 - i]) return false;
        }

        return true;
    }
};
