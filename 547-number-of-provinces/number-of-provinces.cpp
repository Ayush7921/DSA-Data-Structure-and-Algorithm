class Solution {
public:
    void dfs(unordered_map<int , vector<int> >& adj , vector<bool> &vis,int i){

        vis[i]=true ;

        for(int &v : adj[i]){
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        unordered_map<int , vector<int> > adj ;

        int r= isConnected.size();
        int c = isConnected[0].size();

        for(int i = 0 ; i< r ; i++){
            for(int j = i+1 ; j< c ; j++ ){
                if(isConnected[i][j]==1){
                    int u = i+1;
                    int v = j+1;

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }


        int v = r;

        vector<bool> vis(v+1, false);

        int provisions = 0 ;

        for(int i = 1 ; i<= v ; i++){
            if(!vis[i]){
                dfs(adj , vis,i);
                provisions++ ;
            }
        }

        return provisions;
        
    }
};