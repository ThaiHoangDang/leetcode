#include <iostream>
#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // two vectors to keep track of mapping
        vector<char> holder(128, NULL), holder2(128, NULL);

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {

            // do mapping if there is no mapping at those two positions yet
            if (holder[s[i]] == NULL && holder2[t[i]] == NULL)
            {
                holder[s[i]] = t[i];
                holder2[t[i]] = s[i];

                // return false if the index we are about to use has been used before
            }
            else if ((holder[s[i]] != t[i]) ||
                     (holder2[t[i]] != s[i]))
                return false;
        }

        return true;
    }
};