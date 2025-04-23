class Solution {
public:
    int findDigitsSum(int num){
        int sum = 0;
        while(num!=0){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        int maxSize = 0;
        int cnt = 0;

        for (int num=1;num<=n;num++){
            int digitSum = findDigitsSum(num);

            mpp[digitSum]++;
            if (mpp[digitSum] == maxSize) cnt++;
            else if (mpp[digitSum] > maxSize){
                maxSize = mpp[digitSum];
                cnt = 1;
            }
        }
        return cnt;
    }
};