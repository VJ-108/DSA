class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> mpp;
        for (auto it: dominoes){
            vector<int> temp = {it[0],it[1]};
            sort(temp.begin(),temp.end());
            mpp[temp]++;
        }
        int cnt = 0;
        for (auto [key,value]: mpp){
            if (value > 1) cnt += (value*(value-1))/2;
        }
        return cnt;
    }
};