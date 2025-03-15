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
        }
        return k<=0;
    }
    int minCapability(vector<int>& nums, int k) {
        int mini = INT_MAX,maxi = INT_MIN;
        for (auto it: nums){
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        int low = mini,high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (canHave(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};