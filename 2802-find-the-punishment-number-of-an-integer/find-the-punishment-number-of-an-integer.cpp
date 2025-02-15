class Solution {
public:
    bool rec(int i, int currSum, string prod, int target) {
        if (i == prod.size()) return currSum == target;

        int num = 0;
        for (int j = i; j < prod.size(); j++) {
            num = num * 10 + (prod[j] - '0');
            if (rec(j + 1, currSum + num, prod, target)) return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            string squared = to_string(i * i);
            if (rec(0, 0, squared, i)) sum += i * i;
        }
        return sum;
    }
};