class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> ans;

        // Step 1: Record the last index of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Iterate and determine partitions
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);  // Expand partition to include all occurrences

            if (i == end) {  // Partition found
                ans.push_back(end - start + 1);
                start = i + 1;  // Move to next partition
            }
        }

        return ans;
    }
};
