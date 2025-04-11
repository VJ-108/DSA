class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (auto str : strs) {
            // string temp = str;
            // sort(temp.begin(), temp.end());
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }
            string temp;
            for (int c : count) {
                temp += '#' + to_string(c);
            }
            mpp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto [key, group] : mpp) {
            ans.push_back(group);
        }
        return ans;
    }
};