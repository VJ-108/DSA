class Solution {
public:
    string rec(string s) {
        string ans = "";
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        ans += to_string(count) + s.back();
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++) {
            ans = rec(ans);
        }
        return ans;
    }
};