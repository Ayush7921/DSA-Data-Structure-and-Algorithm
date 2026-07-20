class Solution {
public:
    bool iscycle( unordered_map<int,vector<int>> &adj , vector<int>& vis ,vector<int>& inpath , int u  ){
        vis[u]=true;
        inpath[u]=true;

        for(int &v : adj[u] ){

            if(!vis[v]){
                if(iscycle(adj , vis , inpath , v)){
                    return true ;
                }
                
            }else if(inpath[v]){
                return true ;
            }
        }

        inpath[u]=false;

        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prequisites) {
        int V = numCourses ;
        int n =prequisites.size();

        unordered_map<int,vector<int>> adj ;

        for(int i = 0 ; i< n ; i++){
            adj[prequisites[i][1]].push_back(prequisites[i][0]);
        }

        vector<int> vis(V,false);
        vector<int> inpath(V,false);

        for(int i = 0 ; i< V ; i++){
            if(!vis[i] && iscycle(adj , vis , inpath , i)){
                return false ;
            }
        }

        return true ;

    }
};