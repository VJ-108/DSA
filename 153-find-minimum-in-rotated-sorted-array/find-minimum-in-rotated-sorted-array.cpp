class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum must be in the right part
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Minimum could be at mid or to the left
                high = mid;
            } else {
                // nums[mid] == nums[high], can't decide, shrink high
                high--;
            }
        }

        return nums[low];
    }
};