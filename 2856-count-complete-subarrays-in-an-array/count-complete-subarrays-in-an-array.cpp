class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for (auto it: nums) st.insert(it);
        int cnt = 0;

        for (int i=0;i<nums.size();i++){
            set<int> temp;
            for (int j=i;j<nums.size();j++){
                temp.insert(nums[j]);
                if (temp.size()==st.size()){
                    cnt += nums.size()-j;
                    break;
                }
            }
        }

        return cnt;
    }
};