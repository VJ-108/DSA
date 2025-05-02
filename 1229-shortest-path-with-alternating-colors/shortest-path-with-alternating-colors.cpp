class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //T.C: O(n + E), S.C: O(n + E)

        // 0 -> Red , 1 -> Blue
        // Adjacency list with edge color: 0 (red), 1 (blue)
        vector<vector<pair<int, int>>> adj(n); // O(N + E) space
        for (auto it : redEdges) adj[it[0]].push_back({it[1], 0}); // O(R)
        for (auto it : blueEdges) adj[it[0]].push_back({it[1], 1}); // O(B)

        vector<int> ans(n, -1);

        vector<vector<bool>> visited(n, vector<bool>(2, false)); // visited[node][color] — O(2N)

        // q -> {node, distance, last_edge_color}
        queue<tuple<int, int, int>> q; // O(N) space in worst case
        q.push({0, 0, -1}); // Start from node 0 with no previous edge
        visited[0][0] = visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty()) { // O(N + E)
            auto [node, dist, last_col] = q.front();
            q.pop();

            for (auto [nei, edge_col] : adj[node]) { // O(out-degree(node))
                if (edge_col != last_col && !visited[nei][edge_col]) {
                    visited[nei][edge_col] = true;
                    q.push({nei, dist + 1, edge_col});
                    if (ans[nei] == -1) ans[nei] = dist + 1;
                }
            }
        }

        return ans;

        /*

        //T.C: O(n * (n + E) log n), S.C: O(n + E)

        // 0 -> Red , 1 -> Blue
        // Adjacency list with edge color: 0 (red), 1 (blue)
        vector<vector<pair<int, int>>> adj(n); // O(N + E) space

        for (auto it : redEdges) adj[it[0]].push_back({it[1], 0}); // O(R)
        for (auto it : blueEdges) adj[it[0]].push_back({it[1], 1}); // O(B)

        vector<int> ans; // O(N) space

        for (int i = 0; i < n; i++) { // O(n * (n + E) log n)
            bool isdone = false;

            // Min-heap priority queue: {distance, {node, color_of_last_edge}}
            priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>
            > pq; // O(N) space in worst case

            pq.push({0, {0, -1}}); // Start from node 0 with no previous edge color

            map<pair<int, int>, int> mpp; // To track visited (node, color) states — O(N) space

            while (!pq.empty()) { // O((N + E) log N) per iteration
                int d = pq.top().first;
                int node = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();

                mpp[{node, col}] = 1;

                if (node == i) {
                    isdone = true;
                    ans.push_back(d);
                    break;
                }

                for (auto [it, adj_col] : adj[node]) { // O(out-degree(node))
                    if (col != -1 && adj_col == col) continue; // skip if same color as previous edge
                    if (mpp.find({it, adj_col}) == mpp.end()) {
                        pq.push({d + 1, {it, adj_col}}); // Push new path with alternating color
                    }
                }
            }

            if (!isdone) ans.push_back(-1); // If unreachable
        }

        return ans;
        
        */
    }
};
