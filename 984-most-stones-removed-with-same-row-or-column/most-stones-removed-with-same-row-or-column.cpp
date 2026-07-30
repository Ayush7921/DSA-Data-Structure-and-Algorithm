class Solution {
public:
    vector<int> parent ;
    vector<int> rank;

    int find (int i){
        if(i==parent[i]){
            return i ;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int i , int j ){
        int x = find(i);
        int y = find(j);

        if(x==y){
            return ;
        }

        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if (rank[x]<rank[y]){
            parent[x]=y;
        }else{
            parent[y]=x;
            rank[x]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int mr = 0 ;
        int mc = 0 ;

        for(auto &c : stones){
            mr = max(mr , c[0]);
            mc = max(mc , c[1]);
        }
        
        int n = mr + mc + 2 ;
        parent.assign(n,0);
        for(int i = 0 ; i<n ; i++ ){
            parent[i]=i ;
        }

        rank.assign(n ,0);

        vector<bool> mp(n,false) ;

        for(auto & c : stones ){
            int r = c[0];
            int col = mr + 1 + c[1];

            Union(r,col);

            mp[r]=true;
            mp[col]=true;
        }

        int c = 0 ;
        for(int i = 0 ; i< n; i++){
            if(mp[i] && parent[i]==i){
                c++;
            }
        }

        return stones.size()-c;       
    }
};