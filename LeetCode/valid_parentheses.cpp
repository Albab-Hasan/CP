#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isValid(string s) {
            stack<char> st;

            unordered_map<char, char> bracketMap = {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
            for (char ch : s) {
                if (bracketMap.find(ch) != bracketMap.end()) {
                    if (!st.empty() && st.top() == bracketMap[ch]) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    st.push(ch);
                }
            }
            return st.empty();
        }
};