class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int left = 0, right = 0;
        // int maxlen = 0;
        // int zerosCount = 0;
        
        // while (right < nums.size()) {
        //     if (nums[right] == 0) {
        //         zerosCount++;
        //     }
            
        //     while (zerosCount > k) {
        //         if (nums[left] == 0) {
        //             zerosCount--;
        //         }
        //         left++;
        //     }
            
        //     maxlen = max(maxlen, right - left + 1);
        //     right++;
        // }
        
        // return maxlen;

        int left = 0, right = 0;
        int maxi = 0;
        int temp = k;
        while(right<nums.size()){
            if (nums[right]==0){
                if (temp==0){
                    while(nums[left]!=0) left++;
                    left++;
                    temp++;
                }
                temp--;
            }
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};