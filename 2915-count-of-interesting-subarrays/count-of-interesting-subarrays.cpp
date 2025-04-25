class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // long long cnt = 0;
        // for (int i=0;i<nums.size();i++){
        //     int temp = 0;
        //     for (int j=i;j<nums.size();j++){
        //         if (nums[j]%modulo==k) temp++;
        //         if (temp%modulo==k) cnt++;
        //     }
        // }
        // return cnt;

        int n = nums.size();

        unordered_map<int, long long> mp; //remainder -> count
        long long sum = 0; //sum will be equal to cnt of those elements % m == k

        long long result = 0;

        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k)
                sum += 1;

            int r1 = sum%modulo;

            int r2 = (r1 - k + modulo) % modulo;

            result += mp[r2];
            mp[r1]++;
        }

        return result;
    }
};