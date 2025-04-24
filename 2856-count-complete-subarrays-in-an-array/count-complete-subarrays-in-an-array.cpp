class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for (auto it: nums) st.insert(it);
        int cnt = 0;

        // for (int i=0;i<nums.size();i++){
        //     set<int> temp;
        //     for (int j=i;j<nums.size();j++){
        //         temp.insert(nums[j]);
        //         if (temp.size()==st.size()){
        //             cnt += nums.size()-j;
        //             break;
        //         }
        //     }
        // }

        int left = 0,right = 0;
        map<int,int> mpp;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()==st.size()){
                cnt += nums.size() - right;
                mpp[nums[left]]--;
                if (mpp[nums[left]]<=0) mpp.erase(nums[left]);
                left++;
            }
            right++;
        }

        return cnt;
    }
};