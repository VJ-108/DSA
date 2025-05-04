// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         unordered_map<TreeNode*, TreeNode*> parent_track;
//         unordered_map<TreeNode*, bool> visited;
//         queue<TreeNode*> queue;
//         queue.push(root);
//         while(!queue.empty()) {
//             TreeNode* current = queue.front(); queue.pop();
//             if(current->left) {
//                 parent_track[current->left] = current;
//                 queue.push(current->left);
//             }
//             if(current->right) {
//                 parent_track[current->right] = current;
//                 queue.push(current->right);
//             }
//         }
//         queue.push(target);
//         visited[target] = true;
//         int curr_level = 0;
//         while(!queue.empty()) {
//             int size = queue.size();
//             if(curr_level++ == K) break;
//             for(int i=0; i<size; i++) {
//                 TreeNode* current = queue.front(); queue.pop();
//                 if(current->left && !visited[current->left]) {
//                     queue.push(current->left);
//                     visited[current->left] = true;
//                 }
//                 if(current->right && !visited[current->right]) {
//                     queue.push(current->right);
//                     visited[current->right] = true;
//                 }
//                 if(parent_track[current] && !visited[parent_track[current]]) {
//                     queue.push(parent_track[current]);
//                     visited[parent_track[current]] = true;
//                 }
//             }
//         }
//         vector<int> result;
//         while(!queue.empty()) {
//             TreeNode* current = queue.front(); queue.pop();
//             result.push_back(current->val);
//         }
//         return result;
//     }
// };

class Solution {
    void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp){
        if (root==NULL) return;
        if (root->left!=NULL){
            mpp[root->left] = root;
            dfs(root->left,mpp);
        }
        if (root->right!=NULL){
            mpp[root->right] = root;
            dfs(root->right,mpp);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mpp;
        dfs(root,mpp);
        vector<int> ans;
        unordered_set<TreeNode*> st;

        queue<pair<int,TreeNode*>> q;
        q.push({0,target});
        st.insert(target);

        while(!q.empty()){
            int steps = q.front().first;
            TreeNode* curr = q.front().second;
            q.pop();
            if (steps == k) ans.push_back(curr->val);

            if (curr->left!=NULL && st.find(curr->left)==st.end()){
                q.push({steps+1,curr->left});
                st.insert(curr->left);
            }
            if (curr->right!=NULL && st.find(curr->right)==st.end()){
                q.push({steps+1,curr->right});
                st.insert(curr->right);
            }
            if (mpp[curr] && st.find(mpp[curr])==st.end()){
                q.push({steps+1,mpp[curr]});
                st.insert(mpp[curr]);
            }
        }   
        return ans;
    }
};