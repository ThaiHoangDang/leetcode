#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    string reverseWords(string s) {
        string result, temp;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && (! temp.empty())) {
                result = temp + " " + result;
                temp.clear();
            } else if (s[i] != ' ') {
                temp += s[i];
            }
        }

        if (! temp.empty()) {
            result = temp + " " + result;
        }

        return result.substr(0, result.length() - 1);
    }
};
