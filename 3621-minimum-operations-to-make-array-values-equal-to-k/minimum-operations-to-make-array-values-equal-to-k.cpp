class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // int op=0;
        // unordered_set <int> st;
        // for (auto it: nums){
        //     if (it<k) return -1;
        //     if (st.find(it)==st.end() && it>k){
        //         st.insert(it);
        //         op++;
        //     }
        // }
        // return op;

        //Bitset approach O(n), O(1)
        int mini = *min_element(nums.begin(), nums.end());
        if (mini < k) return -1;

        bitset<100001> st;
        for (int i : nums) if (i > k) st.set(i);    
        return st.count();
    }
};