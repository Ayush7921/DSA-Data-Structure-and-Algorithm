class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i ){
        if(i==parent[i]){
            return i ;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int i , int j ){
        int x = find(i);
        int y = find(j);

        if(x==y){ return ;}

        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if(rank[x]<rank[y]){
            parent[x]=y;
        }else{
            parent[y]=x;
            rank[x]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        parent.resize(n+1);

        for(int i = 0 ; i <= n ; i++){
            parent[i]=i;
        }

        rank.resize(n+1,0);

        for(auto &e : edges){
            int u = find(e[0]);
            int v = find(e[1]);

            if(u==v){
                return e ;
            }else{

                Union(e[0],e[1]);
            }
        }

        return {};

        
    }
};