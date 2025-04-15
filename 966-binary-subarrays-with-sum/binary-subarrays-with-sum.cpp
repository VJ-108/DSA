class Solution {
public:
    int cal(vector<int>& A, int S){
       if (S < 0) return 0;
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            S -= A[j];
            while (S < 0)
                S += A[i++];
            res += j - i + 1;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cal(nums,goal)-cal(nums,goal-1);
    }
};