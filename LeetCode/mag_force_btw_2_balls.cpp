#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxDistance(vector<int>& position, int m) {
            std::sort(position.begin(), position.end());

            int l = 1;
            int r = position.back() - position.front();

            while (l < r) {
                const int mid = r - (r - l) / 2;
                if(numballs(position, mid) >= m)
                    l = mid;
                else 
                    r = mid - 1;
            }
            return l;
        }
    private:
        int numballs(const vector<int>& position, int force) {
            int balls = 0;

            int prevPosition = -force;
            for (const int pos : position)
                if (pos - prevPosition >= force) {
                    ++balls;
                    prevPosition = pos;
                }
        return balls;
    }
};
