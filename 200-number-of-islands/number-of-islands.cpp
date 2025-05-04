class Solution {
    void dfs(vector<vector<char>> &grid,vector<vector<int>>&vis,int r,int c){
        vis[r][c] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for (int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(grid,vis,nr,nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};