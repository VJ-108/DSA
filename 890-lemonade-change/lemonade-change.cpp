class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cntOfFive = 0;
        int cntOfTen = 0;
        int cntOfTwenty = 0;
        for (auto it: bills){
            if (it == 5) cntOfFive++;
            else if (it == 10){
                if (cntOfFive > 0) cntOfFive--;
                else return false;
                cntOfTen++;
            }
            else {
                if (cntOfTen > 0){
                    if (cntOfFive > 0) cntOfFive--;
                    else return false;
                    cntOfTen--;
                }
                else{
                    if (cntOfFive >= 3) cntOfFive = cntOfFive - 3;
                    else return false;
                }
                cntOfTwenty++;
            }
        }
        return true;
    }
};