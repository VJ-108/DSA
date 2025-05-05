class Solution {
public:
    int compare(bool state, vector<int>& nums, int target){
        int n = nums.size();
        int r = n - 1, l = 0, result = -1;
        while (r >= l) {
            int mid = (r + l) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (state) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = compare(true, nums, target);
        int e = compare(false, nums, target);
        return {s, e};
    }
};