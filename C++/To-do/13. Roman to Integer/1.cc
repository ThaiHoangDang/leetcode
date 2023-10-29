#include <string>
using namespace std;

// time:
// space:

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') result += 1;
            else if (s[i] == 'V') result += 5;
            else if (s[i] == 'X') result += 10;
            else if (s[i] == 'L') result += 50;
            else if (s[i] == 'C') result += 100;
            else if (s[i] == 'D') result += 500;
            else if (s[i] == 'M') result += 1000;
        }

        return result;
    }
};
