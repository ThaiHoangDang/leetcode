#include <string>
using namespace std;

// approach: two pointers
// time: O(n)
// space: O(1)


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int backS = s.size() - 1, backT = t.size() - 1, skipS = 0, skipT = 0;

        while (backS >= 0 || backT >= 0) {
            
            // keep track of num # for S
            if (backS >= 0 && s[backS] == '#') {
                skipS++; backS--; continue;
            }

            // keep track of num # for T
            if (backT >= 0 && t[backT] == '#') {
                skipT++; backT--; continue;
            }

            // skip char based on number of #
            if (skipS > 0) {
                skipS--; backS--; continue;
            }

            // skip char based on number of #
            if (skipT > 0) {
                skipT--; backT--; continue;
            }

            // compare chars
            if ((backS >= 0) && (backT >= 0) && (s[backS] != t[backT])) return false;
            else if ((backS < 0 && backT >= 0) || (backS >= 0 && backT < 0)) return false;
            else {
                backS--; backT--;
            }
        }

        return true;
    }
};