class Solution {
public:
    // void rec(vector<int>& arr, unordered_map<int, int>& mpp, int a, int b, int& cnt) {
    //     if (b >= arr.size() || mpp.find(arr[a] + arr[b]) == mpp.end()) {
    //         return;
    //     }
    //     cnt++;
    //     rec(arr, mpp, b, mpp[arr[a] + arr[b]], cnt);
    // }

    int lenLongestFibSubseq(vector<int>& arr) {
        // unordered_map<int, int> mpp;
        // for (int i = 0; i < arr.size(); i++) {
        //     mpp[arr[i]] = i;
        // }
        // int ans = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = i + 1; j < arr.size(); j++) {
        //         int cnt = 2;
        //         rec(arr, mpp, i, j, cnt);
        //         ans = max(ans, cnt);
        //     }
        // }
        // return ans > 2 ? ans : 0;

        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int prev = arr[i],cur = arr[j];
                int nxt = prev + cur;
                int cnt = 2;
                while (mpp.find(nxt) != mpp.end()){
                    cnt++;
                    prev = cur;
                    cur = nxt;
                    nxt = prev + cur;
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
