class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int mini1 = INT_MAX,mini2 = INT_MAX;
        for(int n:nums){
            if(n<=mini1) mini1=n;
            else if(n<=mini2) mini2=n;
            else return true;
        }
        return false;
    }
};