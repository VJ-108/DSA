class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inorder(n,0);
        vector<int> ans;
        for (auto it: edges) inorder[it[1]]++;
        for (int i=0;i<n;i++) if (inorder[i]==0) ans.push_back(i);
        return ans;
    }
};