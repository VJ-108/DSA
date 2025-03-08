class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0;
        int recolor = 0;
        int res = k;
        for (int r=0;r<blocks.size();r++){
            if (blocks[r]=='W') recolor++;
            if (r-l+1==k){
                res = min(res,recolor);
                if (blocks[l]=='W'){
                    recolor--;
                }
                l++;
            }
        }
        return res;
    }
};