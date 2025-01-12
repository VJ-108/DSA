class Solution {
public:
    bool helper(string &s, unordered_set<string> &wordSet, vector<int> &memo, int start) {
        if (start == s.size()) return true; 
        if (memo[start] != -1) return memo[start]; 

        for (int end = start + 1; end <= s.size(); end++) {
            if (wordSet.count(s.substr(start, end - start)) && helper(s, wordSet, memo, end)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return helper(s, wordSet, memo, 0);
    }

};