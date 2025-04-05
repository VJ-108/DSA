class Solution {
public:
    int func(vector<int>&nums,int i,int xo){
        if (i>=nums.size()) return xo;
        int notTake = func(nums,i+1,xo);
        int take = func(nums,i+1,xo^nums[i]);
        return take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return func(nums,0,0);
    }
};