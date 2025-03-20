class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi=INT_MIN;
        for (auto it: candies) maxi = max(maxi,it);
        for (auto it: candies){
            if (it+extraCandies >= maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};