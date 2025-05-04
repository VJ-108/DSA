class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        /*
        The | operator is used to set specific bits in a bitmask.
        If you have the following two bitmasks:
        key_mask = 0b000010 (which represents the key 'b' being collected)
        new_key = 0b000001 (which represents the key 'a' being collected)
        Using | on these two bitmasks: key_mask |= new_key;
        key_mask = 0b000011 (Now both 'a' and 'b' keys are collected, represented by the 0th and 1st bits being 1)
        */
        /*
        If you have the following two bitmasks:
        key_mask = 0b000011 (which means keys 'a' and 'b' are collected)
        door = 0b000100 (which represents a door 'C' that requires the key 'c', the 2nd bit)
        Using & to check if the key 'c' is collected:
        1 << (door - 'A') shifts 1 to the bit position corresponding to the key required
        For door 'C', this becomes 1 << 2, or 0b100.
        key_mask & 0b100 checks if the 2nd bit in key_mask is set to 1.
        If key_mask is 0b000011 (which means keys 'a' and 'b' are collected), the result of 0b000011 & 0b100 is 0b000000 (which is 0). Therefore, it means key 'c' has not been collected, so we cannot pass through door 'C'.
        */
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
        // visited[r][c][key_mask] is true if we have visited cell (r, c) with the key_mask
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false))); 
        
        q.push({start_r, start_c, 0, 0});
        visited[start_r][start_c][0] = true;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
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