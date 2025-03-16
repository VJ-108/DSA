class Solution {
public:
    bool canRepair(vector<int>& ranks, int cars, long long mid){
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(mid / rank);
            if (totalCars >= cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1,high = 1e18;
        while(low<high){
            long long mid = low + (high-low)/2;
            if (canRepair(ranks,cars,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return high;
    }
};