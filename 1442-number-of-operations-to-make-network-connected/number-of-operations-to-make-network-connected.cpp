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

    int makeConnected(int n, vector<vector<int>>& connections) {

        int x = connections.size();

        if(x<n-1){
            return -1;
        }
        parent.assign(n,0);

        for(int i = 0 ; i < n ; i++){
            parent[i]=i;
        }

        rank.assign(n,0);
        
        
        for(auto &e: connections){
            Union(e[0],e[1]);
        }

        int ans=-1 ;

        for(int i = 0 ; i< n ; i++){
            if(i==parent[i]){
                ans++;
            }
        }

        return ans;
        
    }
};