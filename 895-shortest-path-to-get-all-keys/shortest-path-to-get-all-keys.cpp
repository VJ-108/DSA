class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int all_keys = 0;
        int start_r, start_c;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char cell = grid[i][j];
                if (cell == '@') {
                    start_r = i;
                    start_c = j;
                } else if (cell >= 'a' && cell <= 'f') {
                    all_keys |= (1 << (cell - 'a'));
                }
            }
        }

        queue<tuple<int, int, int, int>> q;  // (r, c, steps, key_mask)
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        
        q.push({start_r, start_c, 0, 0});
        visited[start_r][start_c][0] = true;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        
        while (!q.empty()) {
            auto [r, c, steps, keys] = q.front();
            q.pop();
            
            if (keys == all_keys) return steps;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char ch = grid[nr][nc];
                
                if (ch == '#') continue;
                
                int new_keys = keys;
                if (ch >= 'a' && ch <= 'f') {
                    new_keys |= (1 << (ch - 'a'));
                } else if (ch >= 'A' && ch <= 'F') {
                    if (!(keys & (1 << (ch - 'A')))) continue;
                }
                
                if (!visited[nr][nc][new_keys]) {
                    visited[nr][nc][new_keys] = true;
                    q.push({nr, nc, steps + 1, new_keys});
                }
            }
        }
        return -1;
    }

};