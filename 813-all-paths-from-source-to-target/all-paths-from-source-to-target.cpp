class Solution {
private:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> temp,int node){
        if (node == graph.size()-1){
            ans.push_back(temp);
            return;
        }
        for (auto it: graph[node]){
            temp.push_back(it);
            dfs(graph,ans,temp,it);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(graph,ans,{0},0);
        return ans;
    }
};