class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        vis[r][c] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                !vis[nr][nc] && grid[nr][nc] >= grid[r][c]) {
                dfs(grid, vis, nr, nc);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atlan(m, vector<int>(n, 0));
        vector<vector<int>> ans;

        // Pacific DFS (top and left edges)
        for (int i = 0; i < m; i++) dfs(grid, pac, i, 0);
        for (int j = 0; j < n; j++) dfs(grid, pac, 0, j);

        // Atlantic DFS (bottom and right edges)
        for (int i = 0; i < m; i++) dfs(grid, atlan, i, n - 1);
        for (int j = 0; j < n; j++) dfs(grid, atlan, m - 1, j);

        // Intersection of Pacific and Atlantic reachability
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atlan[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
