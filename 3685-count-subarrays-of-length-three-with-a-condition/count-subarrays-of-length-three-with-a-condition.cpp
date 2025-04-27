class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int i = 0;
        while (i + 2 < nums.size()) {
            if (nums[i] + nums[i+2] == (double)nums[i+1] / 2) {
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};