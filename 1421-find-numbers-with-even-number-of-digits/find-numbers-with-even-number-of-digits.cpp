class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto it: nums){
            int cnt = 0;
            int temp = it;
            while(temp!=0){
                cnt++;
                temp = temp/10;
            }
            if (cnt%2==0) ans++;
        }
        return ans;        
    }
};