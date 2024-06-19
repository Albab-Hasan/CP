#include <bits/stdc++.h>

using namespace std;

int ct(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n = 5;
    cout << "Number of ways to tile a 2x" << n << " board is: " << ct(n) << "\n";

    return 0;
}