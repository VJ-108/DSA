class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // min(a, b) and max(a, b) both range from 0 to 9.
        // So the encoding becomes: 10 * a + b where a ≤ b
        // Maximum key value = 10 * 9 + 9 = 99
        // So keys range from 0 to 99 → total 100 possible values
        int count[100] = {0};
        int result = 0;

        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;
            result += count[key];  
            count[key]++;  
        }

        return result;

        // map<vector<int>,int> mpp;
        // for (auto it: dominoes){
        //     vector<int> temp = {it[0],it[1]};
        //     sort(temp.begin(),temp.end());
        //     mpp[temp]++;
        // }
        // int cnt = 0;
        // for (auto [key,value]: mpp){
        //     if (value > 1) cnt += (value*(value-1))/2;
        // }
        // return cnt;
    }
};