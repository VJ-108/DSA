class Solution {
public:
    bool canGive(vector<int>& candies, int mid, long long k) {
        long long count = 0;
        for (int it : candies) {
            count += it / mid; 
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int it : candies) {
            sum += it;
        }
        
        if (sum < k) return 0; 

        int low = 1, high = sum / k, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canGive(candies, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};
