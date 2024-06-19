#include<bits/stdc++.h>

using namespace std;

unordered_set<int> aps(vector<int>& weight) {
    unordered_set<int> sums;
    sums.insert(0);

    for (int weight : weight) {
        unordered_set<int> new_sums;
        for (int sum : sums) {
            new_sums.insert(sum + weight);
        }
        sums.insert(new_sums.begin(), new_sums.end());
    }
    return sums;
}
int main() {
    vector<int> weight = {1, 2, 3, 4, 5};
    unordered_set<int> sums = aps(weight);

    cout << "All possible sums: ";
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}