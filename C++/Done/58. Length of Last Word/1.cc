#include <iostream>
#include <string>
#include <vector>
using namespace std;

// time: O(n) worst case
// space: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
      int len = 0; // keep track of word length
      bool inWord = false; // tell if we are currently inside a word

      for (int i = s.size() - 1; i >= 0; i--) {
        if (inWord == true && s[i] == ' ') return len; // return if reach the end of the word

        if (s[i] != ' ') {
          inWord = true;
          len++;
        }
      }

      return len;
    }
};
