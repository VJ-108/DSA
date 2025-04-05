class Solution {
public:
    int func(vector<int>&nums,int i,int xo){
        if (i>=nums.size()) return xo;
        int notTake = func(nums,i+1,xo);
        int take = func(nums,i+1,xo^nums[i]);
        return take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        // return func(nums,0,0);

        int sum=0;
        int subset = 1<<nums.size();
        for (int num=0;num<subset;num++){
            int xo = 0;
            for (int i=0;i<nums.size();i++){
                if (num & (1<<i)){
                    xo ^= nums[i];
                }
            }
            sum += xo;
        }
        return sum;
    }
};