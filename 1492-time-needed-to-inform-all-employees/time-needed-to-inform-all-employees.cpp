class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i=0;i<manager.size();i++){
            if (manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>> q; // q -> {node,time}
        q.push({headID,0});

        int gt = informTime[headID];
        while(!q.empty()){
            int node = q.front().first;
            int t = q.front().second;
            q.pop();
            t += informTime[node];
            gt = max(gt,t);
            for (auto it: adj[node]){
                q.push({it,t});
            }
        }
        return gt;
    }
};