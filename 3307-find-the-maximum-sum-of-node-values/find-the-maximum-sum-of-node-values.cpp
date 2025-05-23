class Solution {
public:
    typedef long long ll;
    ll maximumValueSum(vector<int>& nums, int k,vector<vector<int>>& edges) {
        vector<int> gain;
        ll normalSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            gain.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }
        
        sort(gain.begin(), gain.end(), greater<int>());
        
        for (int i = 0; i < gain.size()-1; i += 2) {

            ll pairSum = gain[i] + gain[i + 1];
            
            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
    }
};
