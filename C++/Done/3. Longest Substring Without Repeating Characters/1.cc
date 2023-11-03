#include <vector>
#include <string>
using namespace std;

// arroach: string traversing
// runtime: O(n)
// space: O(n)

class Solution {
public:
    int isIn(string &s, char c) {
        for (int i = 0; i < s.length(); i++) if (s[i] == c) return i;
        return -1;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, curLength = 0, duplicatedIndex;
        string curString = "";

        for (int i = 0; i < s.length(); i++) {
            duplicatedIndex = isIn(curString, s[i]);

            if (duplicatedIndex == -1) {
                curLength++;
            } else {
                curString.erase(0, duplicatedIndex + 1);
                curLength -= duplicatedIndex;
            }
            curString += s[i];
            maxLength = max(maxLength, curLength);
        }

        return maxLength;
    }
};
