class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if (s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &ans,vector<string> &curr,string s,int ind){
        if (ind == s.size()){
            ans.push_back(curr);
            return;
        }

        for (int i=ind;i<s.size();++i){
            if (isPalindrome(s,ind,i)){
                curr.push_back(s.substr(ind,i-ind+1));
                backtrack(ans,curr,s,i+1);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(ans,curr,s,0);
        return ans;
    }
};