class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // vector<int> hidden(differences.size()+1,-1);
        // hidden[0] = lower;
        // int cnt = 0;
        // for (int j = lower;j<=upper;j++){
        //     hidden[0]=j;
        //     for (int i=1;i<hidden.size();i++){
        //         int temp = hidden[i-1]+differences[i-1];
        //         if (temp>=lower && temp<=upper){
        //             hidden[i] = temp;
        //         }else break;
        //     }
        //     if (hidden[hidden.size()-1]!=-1){
        //         cnt = 1;
        //         break;
        //     }
        // }
        // if (cnt==0) return 0;

        // int maxi = INT_MIN;
        // for (auto it: hidden) maxi = max(maxi,it);
        // while(maxi+1>=lower && maxi+1<=upper){
        //     maxi++;
        //     cnt++;
        // }
        // return cnt;



        int curr = 0; 
        int minVal = 0;
        int maxVal = 0;

        for(int &d : differences) {
            curr = curr + d;

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper - maxVal) - (lower - minVal) + 1 <= 0) {
                return 0;
            }
        }

        return (upper - maxVal) - (lower - minVal) + 1;
    }
};