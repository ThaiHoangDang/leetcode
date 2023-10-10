#include <string>
using namespace std;

// time:
// space:


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int backS = s.size() - 1, backT = t.size() - 1, skipS = 0, skipT = 0;

        while (backS >= 0 || backT >= 0) {

            if (backS >= 0 && s[backS] == '#') {
                skipS++; backS--; continue;
            }

            if (backT >= 0 && t[backT] == '#') {
                skipT++; backT--; continue;
            }

            if (skipS > 0) {
                skipS--; backS--; continue;
            }

            if (skipT > 0) {
                skipT--; backT--; continue;
            }

            if ((backS >= 0) && (backT >= 0) && (s[backS] != t[backT])) return false;
            else {
                backS--; backT--;
            }
        }

        if (backS != backT) return false;

        return true;
    }
};