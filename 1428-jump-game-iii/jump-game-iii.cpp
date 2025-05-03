class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start]==0) return true;
        vector<int> vis(arr.size(),0);

        queue<int> q;
        if (start + arr[start] < arr.size()){
            q.push(start+arr[start]);
            vis[start+arr[start]] = 1;
        }
        if (start - arr[start] >= 0){
            q.push(start-arr[start]);
            vis[start-arr[start]] = 1;
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0) return true;
            if (curr + arr[curr] < arr.size() && !vis[curr+arr[curr]]){
                q.push(curr+arr[curr]);
                vis[curr+arr[curr]] = 1;
            }
            if (curr - arr[curr] >= 0 && !vis[curr-arr[curr]]){
                q.push(curr-arr[curr]);
                vis[curr-arr[curr]] = 1;
            }
        }
        return false;
    }
};