class Solution {
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int r,int c){
        vis[r][c] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for (int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==0){
                dfs(grid,vis,nr,nc);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for (int i=0;i<m;i++){
            if (!vis[i][0] && grid[i][0]==0) dfs(grid,vis,i,0);
            if (!vis[i][n-1] && grid[i][n-1]==0) dfs(grid,vis,i,n-1);
        }
        for (int j=0;j<n;j++){
            if (!vis[0][j] && grid[0][j]==0) dfs(grid,vis,0,j);
            if (!vis[m-1][j] && grid[m-1][j]==0) dfs(grid,vis,m-1,j);
        }
        
        int cnt = 0;
        for (int i=1;i<m-1;i++){
            for (int j=1;j<n-1;j++){
                if (!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};