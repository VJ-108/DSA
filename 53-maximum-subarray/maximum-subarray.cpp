class Solution {
public:
    int helper(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }

        int mid = (i + j) / 2;

        int sum = 0, leftMaxSUM = INT_MIN;
        for (int l = mid; l >= i; l--) {
            sum += nums[l];
            leftMaxSUM = max(leftMaxSUM, sum);
        }

        int rightMaxSUM = INT_MIN;
        sum = 0;
        for (int l = mid + 1; l <= j; l++) {
            sum += nums[l];
            rightMaxSUM = max(rightMaxSUM, sum);
        }

        int maxLeftRight = max(helper(nums, i, mid), helper(nums, mid + 1, j));
        return max(maxLeftRight, leftMaxSUM + rightMaxSUM);
    }
    int maxSubArray(vector<int>& nums) {
        // return helper(nums, 0, nums.size() - 1);

        if (nums.size()<1) return 0;
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};