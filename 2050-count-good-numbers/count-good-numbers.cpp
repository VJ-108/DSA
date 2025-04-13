class Solution {
public:
    long long mod = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long result = (power(5, evenCount) * power(4, oddCount)) % mod;
        return result;
    }
};
