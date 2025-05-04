class Solution {
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int r,int c){
        vis[r][c] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int cnt = 0;
        for (int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1){
                cnt += dfs(grid,vis,nr,nc) + 1;
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int ans = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (!vis[i][j] && grid[i][j]==1){
                    int temp = 1;
                    temp += dfs(grid,vis,i,j);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};