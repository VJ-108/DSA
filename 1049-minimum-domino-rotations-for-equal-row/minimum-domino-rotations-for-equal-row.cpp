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

    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int swaps_top = 0, swaps_bottom = 0;
        int n = tops.size();
        
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x)
                return -1;
            if (tops[i] != x) swaps_top++;
            if (bottoms[i] != x) swaps_bottom++;
        }
        
        return min(swaps_top, swaps_bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // auto [ntops_key,ntops_val] = findMajor(tops);
        // auto [nbots_key,nbots_val] = findMajor(bottoms);
        
        // int cnt_top = 0;
        // for (int i=0;i<tops.size();i++){
        //     if (bottoms[i]==ntops_key && tops[i]!=ntops_key) cnt_top++;
        // }
        // int cnt_bot = 0;
        // for (int i=0;i<bottoms.size();i++){
        //     if (tops[i]==nbots_key && bottoms[i]!=nbots_key) cnt_bot++;
        // }
        // if (cnt_top + ntops_val != tops.size() && cnt_bot + nbots_val != bottoms.size()) return -1;
        // return min(cnt_top,cnt_bot);

        int val1 = tops[0];
        int val2 = bottoms[0];
        int res1 = check(val1, tops, bottoms);
        if (res1 != -1)
            return res1;
        return check(val2, tops, bottoms);
    }
};