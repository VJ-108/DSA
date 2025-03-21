class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> hashset;
        vector<string> output;
        for (auto it: supplies){
            hashset.insert(it);
        }
        bool isNewOutputAdded;
        do{
            isNewOutputAdded = false;
            for (int i=0;i<recipes.size();i++){
                if (hashset.find(recipes[i])!=hashset.end()) continue;
                bool isfulfilled = true;
                for (auto it: ingredients[i]){
                    if (hashset.find(it)==hashset.end()){
                        isfulfilled = false;
                        break;
                    }
                }
                if (isfulfilled){
                    hashset.insert(recipes[i]);
                    output.push_back(recipes[i]);
                    isNewOutputAdded = true;
                }
            }
        }while(isNewOutputAdded);
        return output;
    }
};