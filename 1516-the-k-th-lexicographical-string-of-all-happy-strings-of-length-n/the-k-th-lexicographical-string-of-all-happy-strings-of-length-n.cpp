class Solution {
public:
    void generateHappyString(int n, int& k, string temp, string& result) {
        if (temp.length() == n) {
            k--;
            if (k == 0) {
                result = temp;
            }
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (temp.empty() || temp.back() != ch) {
                generateHappyString(n, k, temp + ch, result);
                if (k == 0) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        string result = "";
        generateHappyString(n, k, "", result);
        return result;
    }
};
