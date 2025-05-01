class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); 
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }

        return cnt;
    }
};