class Solution {
public:
    void bfs(vector<vector<char>>& grid , vector<vector<bool>>& vis,int row , int col){
        queue<pair<int , int>> q ;
        q.push({row,col});
        vis[row][col]=true;
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = -1 ; i<=1 ; i++){          
                int newrow = r;
                int newcol = c +i;

                if((newcol>=0 && newcol<m) && grid[newrow][newcol]=='1' && !vis[newrow][newcol]){
                    q.push({newrow,newcol});
                    vis[newrow][newcol]=true;
                }

            }

            for(int i = -1 ; i<=1 ; i++){          
                int newrow = r+i;
                int newcol = c ;

                if((newrow>=0 && newrow<n) && grid[newrow][newcol]=='1' && !vis[newrow][newcol]){
                    q.push({newrow,newcol});
                    vis[newrow][newcol]=true;
                }

            }
        }

    }


    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(r,vector<bool>(c,false));

        for(int row = 0 ; row < r ; row++){
            for(int col = 0 ; col < c ; col++ ){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(grid,vis,row,col);
                    count++;

                }
            }
        }
        return count;
        
    }
};