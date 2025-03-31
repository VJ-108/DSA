class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k==1) return 0;
        int n = weights.size();
        vector<int> splits;
        for (int i=0;i<n-1;i++){
            splits.push_back(weights[i] + weights[i+1]);
        }
        sort(splits.begin(),splits.end());
        long long max_score = weights[0]+weights[n-1];
        long long min_score = weights[0]+weights[n-1];
        int i = n-1;
        int j = 0;
        for (int i = 0; i < k - 1; i++) {
            min_score += splits[i];                    
            max_score += splits[n - 2 - i];
        }
        return max_score - min_score;
    }
};