class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vis[0][0] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!pq.empty()){
            auto [t, rc] = pq.top();
            auto [r, c] = rc; 
            pq.pop();
            if (r==n-1 && c==m-1) return t;
            for (int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    int nt = t;
                    while(nt<grid[nr][nc]) nt++;
                    pq.push({nt+1,{nr,nc}});
                    // cout<<'{'<<nr<<','<<nc<<'}'<<" "<<nt+1<<endl;
                }
            }
        }
        return -1;
    }
};