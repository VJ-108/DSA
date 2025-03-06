#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long sumActual = 0, squareSumActual = 0;
        long long sumExpected = 0, squareSumExpected = 0;

        for (int i = 1; i <= n * n; i++) {
            sumExpected += i;
            squareSumExpected += (long long)i * i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumActual += grid[i][j];
                squareSumActual += (long long)grid[i][j] * grid[i][j];  
            }
        }

        long long S1 = sumActual - sumExpected;  // (R - M)
        long long S2 = squareSumActual - squareSumExpected;  // (R² - M²)

        // Solve for R (repeated) and M (missing)
        long long R = (S1 + (S2 / S1)) / 2;
        long long M = R - S1;

        return {(int)R, (int)M};
    }
};
