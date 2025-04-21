class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            int check = target - nums[i];
            if (mpp.find(check)!=mpp.end()) return {mpp[check],i};
            else mpp[nums[i]]=i;            
        }
        return {-1,-1};
    }
};