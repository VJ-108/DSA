class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> back(n,0);
        int maxi = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            back[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    back[i] = prev;
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        vector<int> ans;
        while (back[maxi] != maxi) {
            ans.push_back(nums[maxi]);
            maxi = back[maxi];
        }
        ans.push_back(nums[maxi]);
        return ans;
    }
};