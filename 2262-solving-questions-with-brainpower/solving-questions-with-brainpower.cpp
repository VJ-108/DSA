class Solution {
public:
    long long func(vector<vector<int>> &questions, int i,vector<long long> &dp){
        if (i>=questions.size()){
            return 0;
        }
        if (dp[i]!=-1) return dp[i];
        long long skip = func(questions, i + 1,dp); 
        long long take = questions[i][0];
        if (i + questions[i][1] + 1 < questions.size()) {
            take += func(questions, i + questions[i][1] + 1,dp);
        }
        return dp[i] = max(skip,take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        // vector<long long> dp(questions.size(),-1);
        // return func(questions,0,dp);

        vector<long long> dp(questions.size()+1,0);
        dp[0]=0;
        for (int i = questions.size() - 1; i >= 0; --i) {
            long long skip = dp[i + 1];
            long long take = questions[i][0];
            if (i + questions[i][1] + 1 < questions.size()) {
                take += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(skip, take);
        }
        
        return dp[0];
    }
};