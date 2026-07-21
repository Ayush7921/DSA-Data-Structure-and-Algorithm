class Solution {
public:
    bool dfs(unordered_map<int , vector<int>> &adj, int u , int d , vector<bool> &vis){
        vis[u]=true;

        for(int &v : adj[u]){
            if(v==d){
                return true ;
            }else if(!vis[v]){
                if(dfs(adj,v,d,vis)){
                    return true ;
                }
            }
        }

        return false ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(source == destination){
            return true;
        }

        unordered_map<int , vector<int>> adj ;

        for(int i = 0 ; i< edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<bool> vis(n,false);
        if(dfs(adj,source,destination,vis)){
            return true ;
        }

        return false ;

    }
};