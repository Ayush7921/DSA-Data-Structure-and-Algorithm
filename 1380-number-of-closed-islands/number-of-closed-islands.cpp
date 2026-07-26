class Solution {
public:
    int tr;
    int tc ;
    const int deltarow[4] = {-1,0,1,0};
    const int deltacol[4] = {0,1,0,-1};

    void dfs(vector<vector<int>>& grid , int u , int v){
        grid[u][v]=-1;

        for(int i = 0 ; i< 4 ; i++){
            int nr = u + deltarow[i];
            int nc = v +deltacol[i];

            if((nr>=0 && nr < tr) && (nc >=0 && nc < tc) && (grid[nr][nc]==0)){
                dfs(grid,nr,nc);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        tr = grid.size();
        tc = grid[0].size();

        for(int i = 0 ; i< tc ; i++){
            if(grid[0][i]==0){
                dfs(grid,0 ,i);
            }
        }

        for(int i = 0 ; i< tr ; i++){
            if(grid[i][tc-1]==0){
                dfs(grid,i ,tc-1);
            }
        }

        for(int i = tc-1 ; i >= 0 ; i--){
            if(grid[tr-1][i]==0){
                dfs(grid,tr-1 ,i);
            }
        }

        for(int i = tr-1 ; i >= 0 ; i--){
            if(grid[i][0]==0){
                dfs(grid,i ,0);
            }
        }

        int count = 0;
        for(int i = 1 ; i< tr-1 ; i++  ){
            for(int j = 1 ; j < tc-1 ; j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count+=1;
                }
            }
        }

        return count ;
    }
};