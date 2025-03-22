class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_set<long long> hash_set;
        
        for (auto& it : edges) {
            dsu.unite(it[0], it[1]);
            long long key1 = (long long)it[0] * n + it[1];
            long long key2 = (long long)it[1] * n + it[0];
            hash_set.insert(key1);
            hash_set.insert(key2);
        }

        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[dsu.find(i)].push_back(i);
        }

        int cnt = 0;
        for (auto& it : mpp) {
            bool temp = true;
            for (int i = 0; i < it.second.size(); i++) {
                for (int j = i + 1; j < it.second.size(); j++) {
                    long long key = (long long)it.second[i] * n + it.second[j];
                    if (hash_set.find(key) == hash_set.end()) {
                        temp = false;
                        break;
                    }
                }
                if (!temp) break;
            }
            if (temp) {
                cnt++;
            }
        }

        return cnt;
    }
};
