class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());

        queue<pair<string,int>> q;
        q.push({startGene,0});

        while(!q.empty()){
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (gene==endGene) return steps;
            for (int i=0;i<gene.size();i++){
                char original = gene[i];
                for (char ch: {'A','C','G','T'}){
                    gene[i]=ch;
                    if (st.find(gene)!=st.end()){
                        st.erase(gene);
                        q.push({gene,steps+1});
                    }
                }
                gene[i]=original;
            }
        }
        return -1;
    }
};