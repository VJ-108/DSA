class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        int i=0,j=n-1;
        while(i<m && j>=0){
            if (grid[i][j] >= 0) i++;
            else{
                ans += (m-i);
                if (j>0 && grid[i][j-1] < 0) j--;
                else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};