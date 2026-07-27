class Solution {
public:

    vector<int> parent;
    vector<int> rank ;
    
    int find(int i){
        if(i==parent[i]){
            return i ;
        }

        return parent[i]=find(parent[i]);

    }

    void Union(int i , int j){

        int x = find(i);
        int y = find(j);

        if(x==y){
            return ;
        }

        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if(rank[x]<rank[y]){
            parent[x]=y;
        }else {
            parent[y]=x;
            rank[x]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isc) {
        
        int n = isc.size();
        parent.resize(n);
        for(int i = 0 ; i< n; i++){
            parent[i]=i;
        }

        rank.resize(n,0);

        for(int i = 0 ; i< n ; i++){
            for(int j = i+1; j<n ; j++){
                if(isc[i][j]==1){
                    Union(i,j);
                }
            }
        }

        int distinct = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) {
                distinct++;
            }
        }

        return distinct;
    }
};