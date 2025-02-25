class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, evenCnt = 1, oddCnt = 0; 
        int ans = 0, MOD = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum % 2 == 0) { 
                ans = (ans + oddCnt) % MOD;
                evenCnt++;
            } else {
                ans = (ans + evenCnt) % MOD;
                oddCnt++;
            }
        }
        
        return ans;
    }
};