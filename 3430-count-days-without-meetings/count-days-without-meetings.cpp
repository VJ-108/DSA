class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());
        int prev_end = 0;
        int start = -1;
        for (auto it: meetings){
            start = max(it[0],prev_end+1);
            int end = it[1];
            days = days - max(0,end-start+1);
            prev_end = max(prev_end,end);
        }
        return days;
    }

};