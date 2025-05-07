class Solution {
public:
    typedef pair<int, pair<int, pair<int,int>>> P;
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{1,{0,0}}});
        vis[0][0] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!pq.empty()){
            auto [t, Altrc] = pq.top();
            auto [Alt, rc] = Altrc;
            auto [r, c] = rc;
            pq.pop();
            if (r==n-1 && c==m-1) return t;
            for (int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    int nt = t;
                    // while(nt<grid[nr][nc]) nt++;
                    nt = max(grid[nr][nc],nt);
                    int newAlt = Alt == 1 ? 2 : 1;
                    pq.push({nt+Alt,{newAlt,{nr,nc}}});
                    // cout<<'{'<<nr<<','<<nc<<'}'<<" "<<nt+1<<endl;
                }
            }
        }
        return -1;
    }
};