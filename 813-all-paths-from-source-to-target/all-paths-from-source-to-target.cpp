class Solution {
private:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int>& vis,vector<int> temp,int node){
        if (node == graph.size()-1){
            ans.push_back(temp);
            return;
        }
        vis[node] = 1;
        for (auto it: graph[node]){
            if (!vis[it]){
                vis[it] = 1;
                temp.push_back(it);
                dfs(graph,ans,vis,temp,it);
                temp.pop_back();
                vis[it] = 0;
            }
        }
        vis[node] = 0;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> vis(graph.size(),0);
        dfs(graph,ans,vis,{0},0);
        return ans;
    }
};