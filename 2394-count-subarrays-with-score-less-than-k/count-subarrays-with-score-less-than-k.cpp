class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int left = 0;
        long long sum = 0, cnt = 0;
        for (int right = 0;right<nums.size();right++){
            sum += nums[right];
            cnt++;
            while(sum*cnt>=k){
                sum = sum-nums[left];
                cnt--;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};