class Solution {
public:
    void flip(vector<int>&nums,int i){
        nums[i]=nums[i]==0?1:0;
        nums[i+1]=nums[i+1]==0?1:0;
        nums[i+2]=nums[i+2]==0?1:0;
    }
    int minOperations(vector<int>& nums) {
        int l=0;
        int cnt=0;
        while(l<nums.size()){
            while(l<nums.size() && nums[l]!=0) l++;
            if (l+2 < nums.size()){
                flip(nums,l);
                cnt++;
            }else break;
        }
        for (auto it: nums){
            if (it==0) return -1;
        }
        return cnt;
    }
};