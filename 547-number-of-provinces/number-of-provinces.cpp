class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {

        int v = isConnected.size();
        vector<bool> vis(v+1, false);

        int provisions = 0 ;

        queue<int > q ;
        for(int i = 1 ; i<= v ; i++){
            if(vis[i]){
                continue;
            }

            vis[i]=true ;
            q.push(i);
            provisions++;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int j = 1 ; j<=v; j++ ){
                    if(!vis[j] && isConnected[u-1][j-1]==1){
                        vis[j]=true ;
                        q.push(j);
                    }
                }
            } 
        }

        return provisions;
        
    }
};