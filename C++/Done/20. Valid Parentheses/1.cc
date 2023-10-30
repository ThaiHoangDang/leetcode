#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool match(char x, char y) {
        if ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) return true;
        return false;
    }

    bool isValid(string s) {
        vector<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.emplace_back(s[i]);
            } else {
                if (stack.empty() || ! match(stack.back(), s[i])) return false;
                else stack.pop_back();
            }
        }

        if (stack.empty()) return true;
        else return false;
    }
};
