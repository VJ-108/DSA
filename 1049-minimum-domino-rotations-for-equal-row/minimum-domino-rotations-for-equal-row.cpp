class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mpp1,mpp2;
        for (int i=0;i<tops.size();i++){
            mpp1[tops[i]]++;
            mpp2[bottoms[i]]++;
        }
        
        int ntops_key = INT_MIN,ntops_val = INT_MIN;
        int nbots_key = INT_MIN,nbots_val = INT_MIN;
        for (auto [key,value]: mpp1){
            if (value > ntops_val){
                ntops_key = key;
                ntops_val = value;
            }
        }
        for (auto [key,value]: mpp2){
            if (value > nbots_val){
                nbots_key = key;
                nbots_val = value;
            }
        }
        
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