#include<bits/stdc++.h>

using namespace std;

int mps(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][n-1];
}

int main(){
    vector<vector<int>> grid = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    cout << "Maximum sum path: " << mps(grid) << "\n";
    return 0;
}