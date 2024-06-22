#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int atMostK(vector<int>& nums, int k) {
        return numberOfSubarrays(nums, k) - numberOfSubarrays(nums, k - 1);
    }
    private:
        int numberOfSubarrays(vector<int>& nums, int k) {
            int ans = 0;
            int i = 0, j = 0;
            int n = nums.size();
            int sum = 0;

            while (j<n) {
                sum+=(nums[j]%2);

                while (i<j&&sum>k) {
                    sum -= (nums[i]%2);
                    i++;
                }
                ans = ans+(j-i+1);
                j++;
            }
            return ans;

        }
};