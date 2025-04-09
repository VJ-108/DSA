class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op=0;
        unordered_set <int> st;
        for (auto it: nums){
            if (it<k) return -1;
            if (st.find(it)==st.end() && it>k){
                st.insert(it);
                op++;
            }
        }
        return op;
    }
};