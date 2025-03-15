class Solution {
public:
    bool canHave(vector<int>& nums,int k, int mid){
        int i=0;
        while(i<nums.size()){
            if (nums[i]<=mid){
                k--;
                i+=2;
            }
            else i++;
            if (k==0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int mini = INT_MAX,maxi = INT_MIN;
        for (auto it: nums){
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        int low = mini,high = maxi;
        while(low<high){
            int mid = low + (high-low)/2;
            if (canHave(nums,k,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return high;
    }
};