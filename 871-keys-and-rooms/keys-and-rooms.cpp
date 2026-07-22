class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms ,int u , vector<bool> &vis ){
        vis[u]=true;

        for(int &v : rooms[u]){

            if(!vis[v]){
                dfs(rooms , v , vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<bool> vis(V,false);

        dfs(rooms , 0 , vis );

        for(int i = 0 ; i<V; i++){
            if(vis[i]==false){
                return false;
            }
        }

        return true ;
        
    }
};