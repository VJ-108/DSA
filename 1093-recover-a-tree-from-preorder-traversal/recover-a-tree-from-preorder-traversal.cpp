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
    TreeNode* findParent(TreeNode* temp,unordered_map <TreeNode*,pair<TreeNode*,int>> mpp,int level){
        if (level-mpp[temp].second==0){
            return mpp[temp].first;
        }
        return findParent(mpp[temp].first,mpp,level);
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int j=0;
        string st = "";
        while(j<traversal.size() && traversal[j]!='-'){
            st += traversal[j];
            j++;
        }
        cout<<j;
        int n;
        stringstream ss(st);
        ss >> n;
        TreeNode* root = new TreeNode(n);
        //child->{parent,childLevel}
        unordered_map <TreeNode*,pair<TreeNode*,int>> mpp;
        // mpp[root]={root,0};
        TreeNode* temp = root;
        int prevCnt=0;
        int currentCnt=0;
        for (int i=j;i<traversal.size();i++){
            if (traversal[i]=='-'){
                currentCnt++;
                continue;
            }
            string str = "";
            while(i+1 < traversal.size() && traversal[i+1]!='-'){
                str += traversal[i];
                i++;
            }
            str += traversal[i];
            int num;
            stringstream ss(str);
            ss >> num;
            if (currentCnt>prevCnt){
                temp->left=new TreeNode(num);
                mpp[temp->left]={temp,currentCnt};
                temp = temp->left;
            }
            // else if (currentCnt==prevCnt){
            //     temp = mpp[temp].first;
            //     temp->right = new TreeNode(traversal[i]-'0');
            //     mpp[temp->right]={temp,currentCnt};
            //     temp = temp->right;
            // }
            else{
                temp = findParent(temp,mpp,currentCnt);
                temp->right = new TreeNode(num);
                mpp[temp->right]={temp,currentCnt};
                temp = temp->right;
            }
            prevCnt=currentCnt;
            currentCnt=0;
        }
        return root;
    }
};