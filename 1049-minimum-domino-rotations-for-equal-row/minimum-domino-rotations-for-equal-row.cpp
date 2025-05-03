class Solution {
public:
    pair<int,int> findMajor(vector<int>&temp){
        int ntemp_key = INT_MIN,ntemp_val = INT_MIN;
        unordered_map<int,int> mpp;
        for (int i=0;i<temp.size();i++){
            mpp[temp[i]]++;
        }

        for (auto [key,value]: mpp){
            if (value > ntemp_val){
                ntemp_key = key;
                ntemp_val = value;
            }
        }

        return {ntemp_key, ntemp_val};
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        auto [ntops_key,ntops_val] = findMajor(tops);
        auto [nbots_key,nbots_val] = findMajor(bottoms);
        
        int cnt_top = 0;
        for (int i=0;i<tops.size();i++){
            if (bottoms[i]==ntops_key && tops[i]!=ntops_key) cnt_top++;
        }
        int cnt_bot = 0;
        for (int i=0;i<bottoms.size();i++){
            if (tops[i]==nbots_key && bottoms[i]!=nbots_key) cnt_bot++;
        }
        if (cnt_top + ntops_val != tops.size() && cnt_bot + nbots_val != bottoms.size()) return -1;
        return min(cnt_top,cnt_bot);
    }
};