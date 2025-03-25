class Solution {
public:
    int count_non_overlapping(vector<pair<int,int>> temp){
        int cnt = 0;
        int prev_end = -1;
        for (auto [start,end]: temp){
            if (prev_end<=start){
                cnt++;
            }
            prev_end = max(prev_end,end);
        }
        return cnt;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if (n<=1) return false;
        vector<pair<int,int>> x,y;
        for (auto it: rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        return max(count_non_overlapping(x),count_non_overlapping(y)) >= 3;
    }
};