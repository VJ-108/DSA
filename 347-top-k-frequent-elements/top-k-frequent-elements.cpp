class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> freqVec;
        for (auto& [num, count] : freq) {
            freqVec.push_back({count, num});
        }

        sort(freqVec.begin(), freqVec.end(), greater<pair<int, int>>());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].second);
        }

        return result;
    }
};