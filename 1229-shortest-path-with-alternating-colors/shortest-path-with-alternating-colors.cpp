class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0 -> Red , 1 -> Blue
        vector<vector<pair<int,int>>> adj(n); //O(4N)

        for (auto it: redEdges) adj[it[0]].push_back({it[1],0}); //O(2N)
        for (auto it: blueEdges) adj[it[0]].push_back({it[1],1}); //O(2N)

        vector<int> ans; //O(N)
        
        for (int i=0;i<n;i++){ //O(N * N * (N*logN))
            bool isdone = false;
            // pq -> {dist, {node,color_of_last_Edge}}
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //O(2N)
            pq.push({0,{0,-1}});
            map<pair<int,int>,int> mpp;
            while(!pq.empty()){ // O(4N)
                int d = pq.top().first;
                int node = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();
                mpp[{node,col}] = 1;
                if (node == i){
                    isdone = true;
                    ans.push_back(d);
                    break;
                };
                for (auto [it,adj_col]: adj[node]){ // O(2N)
                    if (col != -1 && adj_col == col) continue;
                    if (mpp.find({it,adj_col})==mpp.end()){
                        pq.push({d+1,{it,adj_col}}); //O(logN)
                    }
                }
            }
            if (!isdone) ans.push_back(-1);  
        }
        return ans;
    }
};