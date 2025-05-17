class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int cntZero = 0,cntOne = 0,cntTwo = 0;
        // for (auto it: nums){
        //     if (it==0) cntZero++;
        //     if (it==1) cntOne++;
        //     if (it==2) cntTwo++;
        // }
        // int i=0;
        // while(cntZero!=0){
        //     nums[i]=0;
        //     cntZero--;
        //     i++;
        // }
        // while(cntOne!=0){
        //     nums[i]=1;
        //     cntOne--;
        //     i++;
        // }
        // while(cntTwo!=0){
        //     nums[i]=2;
        //     cntTwo--;
        //     i++;
        // }

        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid<=high){
            if (nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};