class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0 -> Red , 1 -> Blue
        vector<vector<pair<int,int>>> adj(n);
        for (auto it: redEdges) adj[it[0]].push_back({it[1],0});
        for (auto it: blueEdges) adj[it[0]].push_back({it[1],1});

        vector<int> ans;
        
        for (int i=0;i<n;i++){
            // int dist = 0;
            bool isdone = false;
            // vector<int> dis(n,1e9);
            // dis[0] = 0;
            // pq -> {dist, {node,color_of_last_Edge}}
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; 
            pq.push({0,{0,-1}});
            map<pair<int,int>,int> mpp;
            while(!pq.empty()){
                int d = pq.top().first;
                int node = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();
                // if (d > dis[node]) continue;
                mpp[{node,col}] = 1;
                if (node == i){
                    isdone = true;
                    ans.push_back(d);
                    break;
                };
                // dist++;
                for (auto [it,adj_col]: adj[node]){
                    if (col != -1 && adj_col == col) continue;
                    if (mpp.find({it,adj_col})==mpp.end()){
                        // if (dis[it] > dis[node] + 1){
                            // dis[it] = dis[node] + 1;
                            pq.push({d+1,{it,adj_col}});
                        // }
                    }
                }
            }
            if (!isdone) ans.push_back(-1);
            // if (!isdone) dist = -1; 
            // ans.push_back(dist);    
        }
        return ans;
    }
};