class Solution {
public:
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     if (grid[0][0]==1) return -1;
    //     int n = grid.size();
    //     if (n == 1 && grid[0][0] == 0) return 1;
    //     queue<pair<int, pair<int,int>>> q;
    //     vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    //     dist[0][0] = 0;       
    //     q.push({0, {0,0}}); 
    //     int dr[] = {-1,0,1,0,-1,1,-1,1};
    //     int dc[] = {0,1,0,-1,1,1,-1,-1};
    //     while (!q.empty()) {
    //         int d = q.front().first; 
    //         int r = q.front().second.first;
    //         int c = q.front().second.second; 
    //         q.pop();
    //         for (int i=0;i<8;i++) {
    //             int newr = r + dr[i];
    //             int newc = c + dc[i];
    //             if (newr<n && newr>=0 && newc<n && newc>=0 && grid[newr][newc]==0){
    //                 if (d + 1 < dist[newr][newc]) {
    //                     dist[newr][newc] = 1 + d;
    //                     if (newr==n-1 && newc==n-1) return d+2;
    //                     q.push({dist[newr][newc], {newr,newc}});
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> vis(n,vector<int>(n,0));

        pq.push({1,{0,0}});
        int drow[] = {-1,0,1,0,-1,1,1,-1};
        int dcol[] = {0,-1,0,1,-1,1,-1,1};
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (vis[r][c]) continue;
            vis[r][c] = 1;
            if (r==n-1 && c==n-1) return dis;
            if (grid[r][c]==1) continue;
            for (int i=0;i<8;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >=0 && nrow<n && ncol >= 0 && ncol<n && grid[nrow][ncol]==0){
                    pq.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};