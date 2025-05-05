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

        unordered_map<int,int> mpp;
        for (int i=1;i<=n;i++) mpp[i]=0;
        for (auto it: trust){
            mpp[it[0]]--;
            mpp[it[1]]++;
        }
        for (auto [key,val]: mpp){
            if (val == n-1) return key;
        }
        return -1;
    }
};