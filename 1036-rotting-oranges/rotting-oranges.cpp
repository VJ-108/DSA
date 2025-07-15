class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>> q;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                else if (grid[i][j]==0) vis[i][j]=1;
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int mt = 0;
        while(!q.empty()){
            auto [t,rc] = q.front();
            auto [r,c] = rc;
            q.pop();

            mt = max(mt,t);
            for (int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr<grid.size() && nr>=0 && nc<grid[0].size() && nc>=0 && vis[nr][nc]==0){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
        }

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1 && vis[i][j]!=1){
                    return -1;
                }
            }
        }
        return mt;
    }
};