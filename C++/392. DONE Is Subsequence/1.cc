#include <string>
using namespace std;

// time: O(n) length of t
// space: O(1)


class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s == t) return true;

        int trackS = 0, trackT = 0;
        
        while (trackT < t.length()) {

            if (s[trackS] == t[trackT]) trackS++;
            if (trackS == s.length()) return true;

            trackT++;
        }

        return false;
    }
};
