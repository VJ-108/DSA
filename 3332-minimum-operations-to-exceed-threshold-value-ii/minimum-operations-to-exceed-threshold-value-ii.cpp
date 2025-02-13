class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        int cnt = 0;

        while (minHeap.top() < k) {
            if (minHeap.size() < 2) return -1;

            int mini1 = minHeap.top(); minHeap.pop();
            int mini2 = minHeap.top(); minHeap.pop();
            
            if (mini2 < k && mini1 * 2 < k && mini1 * 2 + mini2 < k)
                minHeap.push(mini1 * 2 + mini2);
            else minHeap.push(k);
            cnt++;
        }

        return cnt;
    }
};