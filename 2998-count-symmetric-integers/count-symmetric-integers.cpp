class Solution {
public:
    bool isSymmetric(int num){
        string s = to_string(num);
        if (s.size()%2!=0) return false;
        int i=0;
        int sum1 = 0,sum2 = 0;
        while(i<s.size()/2){    
            sum1 += (s[i]-'0');
            sum2 += (s[s.size()-i-1]-'0');
            i++;
        }
        return sum1==sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for (int num=low;num<=high;num++){
            if (isSymmetric(num)) cnt++;
        }
        return cnt;
    }
};