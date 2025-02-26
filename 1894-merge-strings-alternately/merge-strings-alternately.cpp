class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string temp="";
        int i=0,j=0,cnt=0;
        while(i<word1.size() && j<word2.size()){
            if (cnt%2==0){
                temp += word1[i];
                i++;
            }else{
                temp += word2[j];
                j++;
            }
            cnt++;
        }
        while(i<word1.size()){
            temp += word1[i];
            i++;
        }
        while(j<word2.size()){
            temp += word2[j];
            j++;
        }
        return temp;
    }
};