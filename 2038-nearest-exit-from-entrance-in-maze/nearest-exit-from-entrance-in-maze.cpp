class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,pair<int,int>>> q; // q -> {steps,{row,col}};
        q.push({0,{entrance[0],entrance[1]}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[entrance[0]][entrance[1]] = 1;
        while(!q.empty()){
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if ((r == 0 || r == m - 1 || c == 0 || c == n - 1) && !(r == entrance[0] && c == entrance[1])) return steps; 
            for (int i=0;i<4;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr<m && newr>=0 && newc<n && newc>=0 && !vis[newr][newc] && maze[newr][newc] != '+'){
                    q.push({steps+1,{newr,newc}});
                    vis[newr][newc] = 1;
                }
            }
        }
        return -1;
    }
};