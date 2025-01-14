class Solution {
public:
    void reach(string num, int target, vector<string>& ans, string curr,
               long sum, long last, int i) {
        if (i == num.length()) {
            if (sum == target) {
                ans.push_back(curr);
            }
            return;
        }
        for (int j = i; j < num.length(); ++j) {
            string part = num.substr(i, j - i + 1);
            long n = stol(part);

            if (i == 0) {
                reach(num, target, ans, part, n, n, j + 1);
            } else {
                reach(num, target, ans, curr + "+" + part, sum + n, n, j + 1);
                reach(num, target, ans, curr + "-" + part, sum - n, -n, j + 1);
                reach(num, target, ans, curr + "*" + part,
                      sum - last + last * n, last * n, j + 1);
            }
            if (num[i] == '0')
                break;
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        reach(num, target, ans, "", 0, 0, 0);
        return ans;
    }
};