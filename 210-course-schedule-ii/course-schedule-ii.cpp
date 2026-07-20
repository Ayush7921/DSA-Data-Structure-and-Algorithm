class Solution {
public:
    bool dfs(unordered_map<int , vector<int>> &adj,vector<bool> & vis , vector<bool> &inpath ,vector<int> &ans ,int u ){
        vis[u]=true;
        inpath[u]=true;;

        for(int &v : adj[u]){
            if(!vis[v]){
                if(dfs(adj,vis,inpath,ans,v)){
                    return true;
                }
            }else if(inpath[v]){
                return true ;
            }
        }
        ans.push_back(u);
        inpath[u]=false;

        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses ;
        int n = prerequisites.size();
        unordered_map<int , vector<int>> adj;

        vector<int> indegree(V,0);

        for(int i = 0 ; i<n ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            indegree[v]++;
        }
        

        vector<bool> vis(V,false);
        vector<bool> inpath(V,false);
        vector<int> ans ;

        for(int u = 0 ; u< V ; u++)
        {
            if(!vis[u] && dfs(adj , vis,inpath,ans ,u)){
                return {};
            }
        }

        reverse( ans.begin() ,  ans.end()) ;
        return ans ;

        
       
        
    }
};