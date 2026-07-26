class Solution {
public:
    int tr ;
    int tc ;
    const int deltarow[4]={-1,0,1,0};
    const int deltacol[4]={0,1,0,-1};

    void dfs1(vector<vector<int>>& heights,vector<vector<pair<bool , bool>>> &vis,int u ,int v){

        if(vis[u][v].first == true){
            return ;
        }

        vis[u][v].first=true ;

        for(int i = 0 ; i < 4 ; i++){
            int nr = u + deltarow[i];
            int nc = v + deltacol[i];

            if((nr>=0 && nr < tr) && (nc >=0 && nc < tc) && (heights[nr][nc]>=heights[u][v])){
                dfs1(heights,vis,nr,nc);
            }
        }


    }

    void dfs2(vector<vector<int>>& heights,vector<vector<pair<bool , bool>>> &vis,int u ,int v,vector<vector<int>> &ans){

        if(vis[u][v].second == true){
            return ;
        }

        vis[u][v].second=true ;

        if(vis[u][v].first ==true){
            vector<int> temp = {u,v};
            ans.push_back(temp);
        }

        for(int i = 0 ; i < 4 ; i++){
            int nr = u + deltarow[i];
            int nc = v + deltacol[i];

            if((nr>=0 && nr < tr) && (nc >=0 && nc < tc) && (heights[nr][nc]>=heights[u][v])){
                dfs2(heights,vis,nr,nc,ans);
            }
        }


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        tr = heights.size();
        tc= heights[0].size();
        vector<vector<pair<bool , bool>>> vis(tr,vector<pair<bool , bool>>(tc, {false,false}));

        for(int i = 0 ; i<tc ; i++){
            dfs1(heights,vis,0,i);
        }
          
        for(int i = 0 ; i<tr ; i++){
            dfs1(heights,vis,i,0);
        }

        vector<vector<int>> ans ;

        for(int i = 0 ; i<tr ; i++){
            dfs2(heights,vis,i,tc-1,ans);
        }

        for(int i = 0 ; i<tc ; i++){
            dfs2(heights,vis ,tr-1,i,ans);
        }

        return ans ;

    }
};