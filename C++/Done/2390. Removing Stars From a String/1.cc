#include <string>
using namespace std;

// arroach: ... easiest Normal question ...
// runtime: O(n)
// space: O(1)


class Solution {
public:
    string removeStars(string s) {
        string stack;

        for (auto &i : s) {
            if (i != '*') stack += i;
            else stack.pop_back();
        }

        return stack;
    }
};
