#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1), doesn't include the returned vector

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> result;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) result.emplace_back("FizzBuzz");
            else if (i % 3 == 0) result.emplace_back("Fizz");
            else if (i % 5 == 0) result.emplace_back("Buzz");
            else result.emplace_back(to_string(i));
        }

        return result;
    }
};
