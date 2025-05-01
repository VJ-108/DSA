class Solution {
public:
    bool canDo(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid){
        int pillsUsed = 0;
        multiset<int> st(begin(workers),begin(workers)+mid); //best mid workers

        for (int i=mid-1;i>=0;i--){
            int reqrd = tasks[i];
            auto it = prev(st.end());

            if (*it >= reqrd){
                st.erase(it);
            }else if (pillsUsed >= pills){
                return false;
            }else{
                //find weakest workers which can do this task using pills
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if (weakestWorkerIt == st.end()){
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());
        int low = 0, high = min(tasks.size(),workers.size());
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (canDo(tasks,workers,pills,strength,mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};