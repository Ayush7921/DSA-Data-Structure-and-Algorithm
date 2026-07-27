class Solution {
public:
    
    int V ;

    bool dfs(vector<vector<int>>& graph , int u ,  vector<int> &vis ){

        if(vis[u]==1){
            return false ;
        }

        if(vis[u]==2){
            return true ;
        }
        vis[u]=1;

        for(int &v : graph[u]){

            if(vis[v]==0){
                if(!dfs(graph ,v , vis)){
                    return false;
                }
            }else if(vis[v]==1){
                return false ;
            }
        }

        vis[u]=2;
        return true ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        V = graph.size();
        vector<int>vis(V,0);
        vector<int> ans ;
        for(int i = 0 ; i< V ; i++){
            if(dfs(graph,i,vis)){
                ans.push_back(i);
            }
        }

        return ans ;

    }
};