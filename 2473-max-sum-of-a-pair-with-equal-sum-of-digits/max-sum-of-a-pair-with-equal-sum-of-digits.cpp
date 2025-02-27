class Solution {
public:
    int sumofdig(int n){
        int sum=0;
        while(n>0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mpp;
        int maxi = -1;
        for (int i=0;i<nums.size();i++){
            int sum = sumofdig(nums[i]);
            if (mpp.find(sum)!=mpp.end()){
                if (nums[i] > mpp[sum].first) {
                    mpp[sum].second = mpp[sum].first;
                    mpp[sum].first = nums[i];
                } else if (nums[i] > mpp[sum].second) {
                    mpp[sum].second = nums[i];
                }
                if (mpp[sum].second != -1) {
                    maxi = max(maxi, mpp[sum].first + mpp[sum].second);
                }
            }else{
                mpp[sum] = {nums[i], -1};
            }
        }
        return maxi;
    }
};