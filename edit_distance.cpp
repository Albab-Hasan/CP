#include<bits/stdc++.h>

using namespace std;

int ed(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "kitten";
    string s2 = "sitting";

    cout << "Edit Distance: " << ed(s1, s2) << "\n";

    return 0;
}