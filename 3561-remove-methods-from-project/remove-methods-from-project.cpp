class Solution {
public:
    
    void dfs(int u , vector<vector<int>> &adj, vector<bool> &sus){
        sus[u]=true;

        for(int & v: adj[u]){
            if(!sus[v]){
                dfs(v,adj,sus);
            }
        }
    }

    bool dfs1(int u , vector<vector<int>> &adj, vector<bool> &vis , vector<bool> &sus){
        vis[u]=true;

        for(int & v: adj[u]){
            if(!vis[v]){
                if(sus[v]==true){
                    return true ;
                }
                else if(dfs1(v,adj,vis,sus)){
                    return true ;
                }
            }
        }
        return false ;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<bool> sus(n ,false);
        vector<bool> vis(n,false);

        dfs(k,adj,sus);
        bool flag = false; 

        for(int i = 0; i< n ; i++){
            if(!sus[i] && !vis[i] && dfs1(i , adj , vis, sus)){
                flag=true;
                break;
            }
        }
        
        vector<int> ans;
        if(flag){
            for(int i = 0 ; i< n ; i++){
                ans.push_back(i);
            }
        }else{
            for(int i = 0 ; i< n ; i++){
                if(!sus[i]){
                    ans.push_back(i);
                }
            }
        }

        return ans;

    }
};