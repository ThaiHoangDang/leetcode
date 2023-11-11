#include <vector>
#include <iostream>
using namespace std;

// approach:
// time:
// space:


class Solution {
public:
    int trap(vector<int>& height) {
        int totalAmount = 0, tempAmount = 0;
        bool block = false;

        for (int i = 0; i < height.size(); i++) {
            tempAmount = 0; block = false;

            for (int j = i + 1; j < height.size(); j++) {
                
                if (height[i] > height[j]) tempAmount += height[i] - height[j]; 
                else { i = j - 1; block = true; break; }
            }

            if (block) totalAmount += tempAmount;  
        }

        return totalAmount;
    }
};

[4, 2, 3]