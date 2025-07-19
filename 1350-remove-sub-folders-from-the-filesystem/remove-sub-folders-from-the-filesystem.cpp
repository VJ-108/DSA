class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for (const string& f : folder) {
            if (ans.empty() || f.find(ans.back() + "/") != 0) {
                ans.push_back(f);
            }
        }
        return ans;
    }
};
