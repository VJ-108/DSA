class Solution {
public:
    int func(vector<int>&nums,int i,int xo){
        if (i>=nums.size()) return xo;
        int notTake = func(nums,i+1,xo);
        int take = func(nums,i+1,xo^nums[i]);
        return take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        //Recursion - O(2^n),O(n)
        // return func(nums,0,0);


        // //Power set - O(2^n * n), O(1)
        // int sum=0;
        // int subset = 1<<nums.size();
        // for (int num=0;num<subset;num++){
        //     int xo = 0;
        //     for (int i=0;i<nums.size();i++){
        //         if (num & (1<<i)){
        //             xo ^= nums[i];
        //         }
        //     }
        //     sum += xo;
        // }
        // return sum;


        //Didnt understand a single bit of this code but is O(n),O(1)
        // Step 1: Compute bitwise OR of all elements
        int or_all = 0;
        for (int num : nums) {
            or_all |= num;
        }

        // Step 2: Compute number of subsets that include each bit
        // 2^(n-1) subsets will include each bit
        int multiplier = 1 << (nums.size() - 1);

        // Step 3: Final result
        return or_all * multiplier;
    }
};