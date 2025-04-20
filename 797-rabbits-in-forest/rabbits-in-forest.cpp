class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;
        for (auto it: answers) mpp[it]++;
        int cnt = 0;
        for (auto [key,value]: mpp){
            int groups = ceil((float)value / (key+1));
            cnt += groups*(key+1);
        }
        return cnt;
    }
};