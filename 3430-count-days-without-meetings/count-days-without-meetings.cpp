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
    }

};