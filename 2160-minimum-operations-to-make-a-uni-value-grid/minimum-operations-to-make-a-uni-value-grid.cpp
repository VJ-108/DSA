class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            // Converting to 1D
            vector<int> nums;
            for (auto &row : grid) {
                for (int k : row) {
                    nums.push_back(k);
                }
            }
            sort(nums.begin(), nums.end()); // Sorting
            int target = nums[nums.size()/2];
            long long totalOperations = 0;
            for (int k : nums) {
                int temp = abs(k - target);
                if (temp % x != 0) return -1;
                totalOperations += temp/x; // Counting operations req.
            }
            return totalOperations;
        }
    };