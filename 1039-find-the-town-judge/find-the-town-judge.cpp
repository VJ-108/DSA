class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<int> indegree(n+1,0);
        // vector<int> outdegree(n+1,0);
        // for (auto it: trust){
        //     // outdegree[it[0]]++;
        //     // indegree[it[1]]++;

        // }
        // for (int i=1;i<indegree.size();i++){
        //     if (indegree[i]==n-1 && outdegree[i]==0) return i;
        // }

        vector<int> vec(n+1,0);
        for (auto it: trust){
            vec[it[0]]--;
            vec[it[1]]++;
        }
        for (int i=1;i<=n;i++) if (vec[i]==n-1) return i;
        return -1;
    }
};