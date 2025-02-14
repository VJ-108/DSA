class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();i++){
            bool temp=true;
            for (int j=0;j<grid.size();j++){
                if (i!=j){
                    if (!grid[i][j]) temp = false;
                }
            }
            if (temp){
               return i;
            }   
        }
        return -1;
    }
};