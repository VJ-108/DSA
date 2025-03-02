class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i1=0,i2=0;
        while(i1<nums1.size() && i2<nums2.size()){
            if (nums1[i1][0]==nums2[i2][0]){
                ans.push_back({nums1[i1][0],nums1[i1][1]+nums2[i2][1]});
                i1++;
                i2++;
            }
            else if (nums1[i1][0]<nums2[i2][0]){
                ans.push_back({nums1[i1][0],nums1[i1][1]});
                i1++;
            }
            else{
                ans.push_back({nums2[i2][0],nums2[i2][1]});
                i2++;
            }
        }
        while(i1<nums1.size()){
            ans.push_back({nums1[i1][0],nums1[i1][1]});
            i1++;
        }
        while(i2<nums2.size()){
            ans.push_back({nums2[i2][0],nums2[i2][1]});
            i2++;
        }
        return ans;
    }
};