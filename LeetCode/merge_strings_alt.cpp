#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        string mergeAlternately(string word1, string word2) {
            int i = 0, j = 0;
            string result;
  
            while (i < word1.length() && j < word2.length()) {
                result += word1[i++];
                result += word2[j++];
            }
            result += word1.substr(i);    
            result += word2.substr(j);

        return result;
    }
};