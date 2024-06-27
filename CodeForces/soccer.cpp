#include <iostream>
#include <vector>
using namespace std;

void canScoresNeverBeEqual(int t, vector<pair<pair<int, int>, pair<int, int>>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int x1 = test_cases[i].first.first;
        int y1 = test_cases[i].first.second;
        int x2 = test_cases[i].second.first;
        int y2 = test_cases[i].second.second;
        
        int initial_diff = x1 - y1;
        int final_diff = x2 - y2;
        
        if ((initial_diff > 0 && final_diff > 0) || (initial_diff < 0 && final_diff < 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<pair<int, int>, pair<int, int>>> test_cases(t);
    
    for (int i = 0; i < t; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        test_cases[i] = make_pair(make_pair(x1, y1), make_pair(x2, y2));
    }
    
    canScoresNeverBeEqual(t, test_cases);
    
    return 0;
}
