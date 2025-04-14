/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root,int currMax, int &maxi){
        if (root==NULL){
            return 0;
        }
        int leftVal = func(root->left,currMax,maxi);
        int rightVal = func(root->right,currMax,maxi);
        currMax = max({leftVal+root->val,rightVal+root->val,root->val});
        maxi = max({currMax,leftVal+root->val+rightVal,maxi});
        return currMax;
    }
    int maxPathSum(TreeNode* root) {
        //store max(left+root or right+root or all three or prev_max) and move upward with max value including root i.e currmax
        int maxi = -1001;
        int val = func(root,-1001,maxi);
        return maxi;
    }
};