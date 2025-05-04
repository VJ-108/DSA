class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& board ){
        int m = board.size();
        int n = board[0].size();
        vis[row][col]=1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for (int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && board[row][col]==1){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void bfs(vector<vector<int>>&vis,vector<vector<int>>& board,queue<pair<int,int>>&q){
        int m = board.size();
        int n = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && board[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for (int i=0;i<m;i++){
            if (!vis[i][0] && board[i][0]==1){
                // dfs(i,0,vis,board);
                q.push({i,0});
                vis[i][0]=1;
            }
            if (!vis[i][n-1] && board[i][n-1]==1){
                // dfs(i,n-1,vis,board);
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        for (int j=0;j<n;j++){
            if (!vis[0][j] && board[0][j]==1){
                // dfs(0,j,vis,board);
                q.push({0,j});
                vis[0][j]=1;
            }
            if (!vis[m-1][j] && board[m-1][j]==1){
                // dfs(m-1,j,vis,board);
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }
        bfs(vis,board,q);
        int cnt=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};