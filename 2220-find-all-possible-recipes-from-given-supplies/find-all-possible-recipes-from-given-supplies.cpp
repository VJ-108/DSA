class Solution {
public:
    // vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    //     unordered_set<string> hashset;
    //     vector<string> output;
    //     for (auto it: supplies){
    //         hashset.insert(it);
    //     }
    //     bool isNewOutputAdded;
    //     do{
    //         isNewOutputAdded = false;
    //         for (int i=0;i<recipes.size();i++){
    //             if (hashset.find(recipes[i])!=hashset.end()) continue;
    //             bool isfulfilled = true;
    //             for (auto it: ingredients[i]){
    //                 if (hashset.find(it)==hashset.end()){
    //                     isfulfilled = false;
    //                     break;
    //                 }
    //             }
    //             if (isfulfilled){
    //                 hashset.insert(recipes[i]);
    //                 output.push_back(recipes[i]);
    //                 isNewOutputAdded = true;
    //             }
    //         }
    //     }while(isNewOutputAdded);
    //     return output;
    // }


    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> supp(supplies.begin(), supplies.end());
        vector<int> deg(n, 0);
        unordered_map<string, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (const string& s : ingredients[i]) {
                if (!supp.count(s)) {
                    adj[s].push_back(i);
                    deg[i]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) q.push(i);

        vector<string> ans;
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            auto s=recipes[i];
            ans.push_back(s);
            for (auto j : adj[s]) {
                if (--deg[j] == 0) q.push(j);
            }
        }
        return ans;
    }
};