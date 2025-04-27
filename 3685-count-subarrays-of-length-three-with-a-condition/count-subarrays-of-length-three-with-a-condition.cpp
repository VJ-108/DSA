class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int i = 0;
        while (i + 2 < nums.size()) {
            if (2*(nums[i] + nums[i+2]) == nums[i+1]) cnt++;
            i++;
        }
        return cnt;
    }
};