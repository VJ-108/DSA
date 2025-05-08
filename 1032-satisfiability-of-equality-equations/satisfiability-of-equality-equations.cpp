class DSU{
public:
    vector<int> rank,parent;
    DSU(){
        rank.resize(26,0);
        parent.resize(26,0);
        for (int i=0;i<26;i++) parent[i]=i;
    }
    int find(int node){
        if (node==parent[node])
            return node;
        return parent[node]=find(parent[node]);
    }
    void combine(int x,int y){
        int px = find(x);
        int py = find(y);

        if (px == py) return;
        if (rank[px]>rank[py]) parent[py] = px;
        else if (rank[py]<rank[px]) parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU ds;

        for (auto it: equations){
            int n1 = it[0]-'a';
            int n2 = it[3]-'a';
            if (it[1]=='='){
                ds.combine(n1,n2);
            }
        }
        for (auto it: equations){
            int n1 = it[0]-'a';
            int n2 = it[3]-'a';
            int p1 = ds.find(n1);
            int p2 = ds.find(n2);
            if (it[1]=='!'){
                if (p1==p2) return false;
            }
        }
        return true;
    }
};