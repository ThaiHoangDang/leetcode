#include <iostream>
#include <string>
#include <vector>
using namespace std;

// time: 
// space: 


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> holder (26, NULL), holder2 (26, NULL);
		
		if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {

			if (holder[s[i] - 'a'] == NULL && holder2[t[i] - 'a'] == NULL) {
				holder[s[i] - 'a'] = t[i];
				holder2[t[i] - 'a'] = s[i];
			} else if ((holder[s[i] - 'a'] != t[i]) || 
				(holder2[t[i] - 'a'] != s[i])) return false;
		}

		return true;
    }
};