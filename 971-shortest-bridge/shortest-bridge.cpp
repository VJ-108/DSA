class Solution {
private:
    int n;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    bool isValid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, queue<pair<int, int>>& q) {
        visited[r][c] = true;
        grid[r][c] = 2;  // mark first island
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc)) {
                if (grid[nr][nc] == 1 && !visited[nr][nc]) {
                    dfs(grid, visited, nr, nc, q);
                } else if (grid[nr][nc] == 0) {
                    q.push({r, c});  // add boundary cell only once
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q; //stores only water cells i.e boundary

        // 1. DFS marks the first island cells by 2 and collects its boundary cells for expansion.
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, visited, i, j, q);
                    found = true;
                }
            }
        }

        // 2. BFS expands outward from boundaries to find the shortest path to the second island.
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (isValid(nr, nc) && !visited[nr][nc]) {
                        if (grid[nr][nc] == 1) return steps; // found second island
                        q.push({nr, nc}); 
                        visited[nr][nc] = true;
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
