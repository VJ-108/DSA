class Solution {
public:
    void rec(vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                count++;
                rec(freq, count);
                freq[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) freq[c - 'A']++;
        int count = 0;
        rec(freq, count);
        return count;
    }
};