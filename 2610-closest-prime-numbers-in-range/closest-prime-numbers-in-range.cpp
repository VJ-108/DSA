class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        int limit = sqrt(n);
        for (int i = 5; i <= limit; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int prev = -1, mini = INT_MAX;
        vector<int> result = {-1, -1};

        for (int num = left; num <= right; num++) {
            if (isPrime(num)) {
                if (prev != -1 && (num - prev < mini)) {
                    int diff = num - prev;
                    if (diff == 2) return {prev, num}; 
                    if (diff < mini) {
                        mini = diff;
                        result = {prev, num};
                    }
                }
                prev = num;
            }
        }

        return result;
    }
};