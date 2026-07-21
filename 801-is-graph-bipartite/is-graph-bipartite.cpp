class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u , int clr, vector<int > &vis){

        vis[u]=clr;

        for(int &v : graph[u]){
            if(vis[v]==-1){
                if(dfs(graph,v,1-clr,vis)){
                    return true;
                }
            }else if(vis[v]==clr){
                return true ;
            }
        }
        return false;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int > vis(V,-1);

        for(int u = 0 ; u< V; u++){
            if(vis[u]==-1 && dfs(graph, u ,0,vis)){
                return false;
            } 
        }

        return true;
        
    }
};