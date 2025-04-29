class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for (auto it: nums) maxi = max(it,maxi);

        long long subarray = 0;
        long long cntOfMax = 0;
        int left = 0;
        for (int right = 0;right<nums.size();right++){
            if (nums[right]==maxi) cntOfMax++;
            if (cntOfMax >= k) subarray += nums.size() - right;
            while(cntOfMax >= k){
                if (nums[left]==maxi) cntOfMax--;
                else subarray += nums.size() - right;
                left++;
            }
        }
        return subarray;
    }
};