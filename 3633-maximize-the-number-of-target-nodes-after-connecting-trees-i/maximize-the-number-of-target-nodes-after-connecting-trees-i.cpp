class Solution {
public:
    int bfs(int start, const unordered_map<int, vector<int>>& adj, int k) {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;
        int count = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist > k) continue;

            count++; // count current node

            for (int neighbor : adj.at(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return count;
    }

    vector<int> findCount(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = bfs(i, adj, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<int> count1 = findCount(edges1, k);
        vector<int> count2 = findCount(edges2, k - 1);
        int maxCount2 = *max_element(begin(count2), end(count2));

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = count1[i] + maxCount2;
        }

        return result;
    }
};