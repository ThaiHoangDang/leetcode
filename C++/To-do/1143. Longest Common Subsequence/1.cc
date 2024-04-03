#include <iostream>
#include <string>
#include <vector>
using namespace std;

// time: O(nm)
// space: O(n + m)


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if (text1.length() == 0 || text2.length() == 0) return 0;

        // s1 will be the shorter string
        string s1 = (text1.length() > text2.length()) ? text2 : text1;
        string s2 = (text1.length() > text2.length()) ? text1 : text2;

        
        vector<int> holder (s1.length(), 0);

        for (int i = 0; i < s2.length(); i++) {

            vector<int> temp (s1.length(), 0);
            vector<int> tracker {};
            
            for (int j = s1.length() - 1;  j >= 0; j--) {

                if (i == 0) {
                    if (j == 0) temp[j] = (s1[0] == s2[0]) ? 1 : 0;
                    else temp[j] = (s1[j] == s2[0]) ? 1 : temp[j - 1];

                } else {
                    if (j == 0) temp[j] = holder[0] + ((s1[0] == s2[i]) ? 1 : 0);
                    else temp[j] = max(holder[j], temp[j - 1]) + ((s1[j] == s2[i]) ? 1 : 0);

                }
            }

            holder = temp;

            for (auto i : holder) cout << i << ", ";
            cout << endl;
        }

        return holder.back();
    }
};
