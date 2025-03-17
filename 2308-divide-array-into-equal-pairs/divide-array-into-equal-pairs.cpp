class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // we are checking if every x has a x+1 counterpart somewhere in the array. 
        // If xor1 == 0 (all elements appear twice) and xor2 == 0 (each number can form a consecutive pair)
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            xor1 = nums[i] ^ xor1;
            xor2 = (nums[i] + 1) ^ xor2;
        }
        return xor1 == 0 && xor2 == 0;
    }
};