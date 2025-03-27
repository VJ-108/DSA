class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int cnt=1;
        int curr = nums[0];
        for (int i=1;i<nums.size();i++){
            if (cnt==0){
                curr = nums[i];
                cnt = 1;
                continue;
            }
            if (nums[i]==curr) cnt++;
            else cnt--;
        }

        int total = 0;
        for (int num : nums) {
            if (num == curr) total++;
        }

        int leftCount = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == curr) leftCount++;

            if (leftCount * 2 > (i + 1) && (total - leftCount) * 2 > (nums.size() - i - 1)) {
                return i;
            }
        }
        return -1;

    }
};