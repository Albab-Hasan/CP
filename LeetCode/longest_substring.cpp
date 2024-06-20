#include<bits/stdc++.h>

class Solution {
    public:
        int lengthofLongestSunstring(std::string s) {
            std::unordered_map<char, int> charIndexMap;
            int left = 0;
            int maxLength = 0;

            for (int right = 0; right < s.size(); ++right) {
                char currentChar = s[right];

                if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                    left = charIndexMap[currentChar] + 1;
                }
                charIndexMap[currentChar] = right;

                maxLength = std::max(maxLength, right - left + 1);
            } 
            return maxLength;
        }
};
