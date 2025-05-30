class Solution {
public:
    unordered_map<int, vector<int>> getAdjacencyList(const vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj(edges.size() + 1);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& evenCnt, int& oddCnt) {
        if (mark[curr] == 0) 
            evenCnt++;
        else 
            oddCnt++;
            
        for (int& ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] = mark[curr] == 0 ? 1 : 0;
                dfs(ngbr, adj, curr, mark, evenCnt, oddCnt);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        unordered_map<int, vector<int>> adjA = getAdjacencyList(edges1);
        unordered_map<int, vector<int>> adjB = getAdjacencyList(edges2);

        vector<int> markA(N, -1);
        int evenA = 0, oddA = 0;
        markA[0] = 0;
        dfs(0, adjA, -1, markA, evenA, oddA);

        vector<int> markB(M, -1);
        int evenB = 0, oddB = 0;
        markB[0] = 0;
        dfs(0, adjB, -1, markB, evenB, oddB);

        int maxiB = max(evenB, oddB);
        vector<int> res(N);
        for (int i = 0; i < N; i++)
            res[i] = (markA[i] == 0 ? evenA : oddA) + maxiB;
        return res;
    }
};
