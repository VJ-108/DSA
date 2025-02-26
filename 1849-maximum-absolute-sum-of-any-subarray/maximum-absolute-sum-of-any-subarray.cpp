class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        /*
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
        */


        // Kadane’s Algorithm can be modified to solve this efficiently.
        // Instead of just tracking the maximum subarray sum, we also track the minimum subarray sum.
        // The answer is |maxSum - minSum|, since flipping the sign of a negative subarray maximizes the absolute sum.
        int mini_neg=0,maxi_pos=0,sum=0;
        int ans = INT_MIN;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            if (sum > maxi_pos) maxi_pos = sum;
            if (sum < mini_neg) mini_neg = sum;
        }
        return abs(maxi_pos - mini_neg);
    }
};