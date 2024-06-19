#include<bits/stdc++.h>

using namespace std;

int cS(vector<int>& coins, int n, vector<int>& memo) {
    if (n == 0)
        return 0;
    if (n < 0 || coins.empty())
        return INT_MAX;
    if (memo[n] != -1)
        return memo[n];

    int mC = INT_MAX;

    for (int coin : coins) {
        int numCoins = cS(coins, n - coin, memo);

        if (numCoins != INT_MAX)
            mC = min(mC, numCoins + 1);
    }

    memo[n] = mC;

    return mC;
}

int main(){
    vector<int> coins = {1,3,4};
    int n = 10;

    vector<int> memo(n+1, -1);

    int mC = cS(coins, n, memo);

    if (mC == INT_MAX)
        cout << "Not possible" << "\n";
    else 
        cout << "Solution: " << mC << "\n"; 
}
