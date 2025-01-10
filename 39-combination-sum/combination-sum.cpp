class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>&candidates,int target,vector<int> temp, int i){
        if (target==0){
            ans.push_back(temp);
            return;
        }
        if (i>=candidates.size()) return;
        helper(ans,candidates,target,temp,i+1);
        if (target>=candidates[i]){
            temp.push_back(candidates[i]);
            helper(ans,candidates,target-candidates[i],temp,i);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,candidates,target,temp,0);
        return ans;
    }
};