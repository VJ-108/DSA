class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> hash(10,0);
        for (auto it: digits) hash[it]++;
        
        vector<int> ans;
        for (int num = 100;num<=998;num+=2){
            vector<int> temp(10,0);
           
            int given_num = num;
            while(given_num != 0){
                temp[given_num%10]++;
                given_num = given_num/10;
            }
    
            bool canAdd = true;
            for (int i=0;i<=9;i++){
                if (temp[i]==0) continue;
                if (hash[i]==0 || hash[i]<temp[i]){
                    canAdd = false;
                    break;
                }
            }

            if (canAdd) ans.push_back(num);
        }
        return ans;
    }
};