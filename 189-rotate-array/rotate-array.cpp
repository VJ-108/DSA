class Solution {
public:
    void rev(vector<int> &nums, int i, int j){
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        rev(nums,0,nums.size()-k-1);
        rev(nums,nums.size()-k, nums.size()-1);
        rev(nums,0,nums.size()-1);
    }
};