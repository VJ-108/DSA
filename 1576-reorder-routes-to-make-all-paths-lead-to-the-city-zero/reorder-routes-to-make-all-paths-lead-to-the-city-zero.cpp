class Solution {
public:
    int dfs(vector<vector<int>> &adj, map<pair<int,int>,int> &mpp, vector<int> &vis, int node) {
        vis[node] = 1;
        int cnt = 0;
        for (auto it : adj[node]) {
            if (vis[it]) continue;
            if (mpp.find({node, it}) != mpp.end()) cnt++;  
            cnt += dfs(adj, mpp, vis, it);
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        map<pair<int,int>,int> mpp;
        for (auto it: connections){
            mpp[{it[0],it[1]}] = 1;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        return dfs(adj,mpp,vis,0);
    }
};