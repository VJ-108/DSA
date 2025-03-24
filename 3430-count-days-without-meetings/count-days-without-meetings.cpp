class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());
        
        int totalBusy = 0;
        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end + 1) {
                end = max(end, meetings[i][1]); 
            } else {
                totalBusy += (end - start + 1);
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        totalBusy += (end - start + 1);
        return max(0, days - totalBusy);

        // int prev_end = 0;
        // int start = -1;
        // for (auto it: meetings){
        //     start = max(it[0],prev_end+1);
        //     int end = it[1];
        //     days = days - max(0,end-start+1);
        //     prev_end = max(prev_end,end);
        // }
        // return days;
    }

};