class Solution {
public:
    long long coloredCells(int n) {
        //Sum till nth term of the series 1,2,4,8,12,16,20,...
        long long sum = 0;
        while(n!=1){
            sum = sum + ((n-1)*4);
            n--;
        }
        //above loop work for series 2,4,8,12,.. So has to add 1 for n=1 cell case
        return sum+1;
    }
};