/*Given multiple test cases of n×mn×m grids with '.' and '#' characters,
the problem requires determining the center of a Manhattan circle formed by the '#' characters. 
The center is found by calculating the average of the min and max row and column indices of the
'#' characters and adjusting for 1-based indexing.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> findCenter(int n, int m, const vector<string>& grid) {
    int min_row = n, max_row = -1, min_col = m, max_col = -1;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '#') {
                if (r < min_row) min_row = r;
                if (r > max_row) max_row = r;
                if (c < min_col) min_col = c;
                if (c > max_col) max_col = c;
            }
        }
    }

    int h = (min_row + max_row) / 2 + 1;
    int k = (min_col + max_col) / 2 + 1;

    return {h, k};
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> results;

    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int j = 0; j < n; ++j) {
            cin >> grid[j];
        }
        results.push_back(findCenter(n, m, grid));
    }

    for (const auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
