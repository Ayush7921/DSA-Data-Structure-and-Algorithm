class Solution {
public:
    bool dfs(unordered_map<int ,vector< int>> &adj,vector<int > &vis,int currcolor,int u){
        
        vis[u]=1-currcolor;

        for(int & v : adj[u]){
            if(vis[v]==-1){
                if(dfs(adj , vis ,1-currcolor, v )){
                    return true ;
                }
            }else if(vis[u]==vis[v]){
                return true ;
            }
        }
        
        return false;


    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        unordered_map<int , vector<int>> adj ;

        for(auto &e:dislikes)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

        }
        
        vector<int> vis (n+1,-1);
        for(int i = 1 ; i<=n ; i++  ){
            if(vis[i]==-1 && dfs(adj,vis,1,i)){
                return false ;
            }
        }

        return true ;




    }
};