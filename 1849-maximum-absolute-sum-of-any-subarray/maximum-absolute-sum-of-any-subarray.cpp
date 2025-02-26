class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini_neg=INT_MAX,maxi_pos=INT_MIN,sum=0;
        int ans = INT_MIN;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            ans = max(ans,abs(sum));
            if (sum<0){
                mini_neg = min(mini_neg,sum);
                if (maxi_pos==INT_MIN) continue;
                ans = max(ans,abs(sum-maxi_pos));
            }else{
                maxi_pos = max(maxi_pos,sum);
                if (mini_neg==INT_MAX) continue;
                ans = max(ans,abs(sum-mini_neg));
            }
        }
        return ans;
    }
};