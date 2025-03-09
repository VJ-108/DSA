class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        int l=0,res=0;
        for (int r=1;r<N+k-1;r++){
            if (colors[r%N]==colors[(r-1)%N]){
                l = r;
            }
            if (r-l+1>k){
                l++;
            }
            if (r-l+1==k){
                res++;
            }
        }
        return res;
    }
};