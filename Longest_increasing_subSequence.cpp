#include<bits/stdc++.h>

using namespace std;

int lis(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> lis(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}
int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of LIS is: " << lis(arr) << "\n";
    return 0;
}