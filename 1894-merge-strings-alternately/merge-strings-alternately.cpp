class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans;
        bool temp = true;
        while(i<word1.size() && j<word2.size()){
            if (temp){
                ans += word1[i++];
                temp = false;
            }else{
                ans += word2[j++];
                temp = true;
            }
        }
        while(i<word1.size()){
            ans += word1[i++];
        }
        while(j<word2.size()){
            ans += word2[j++];
        }
        return ans;
    }
};