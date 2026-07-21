class Solution {
public:
    void bfs(vector<vector<char>>& grid , int row , int col){
        queue<pair<int , int>> q ;

        q.push({row,col});
        grid[row][col]='0';

        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i<4 ; i++){          
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];

                if((newcol>=0 && newcol<m) && (newrow>=0 && newrow<n) && (grid[newrow][newcol]=='1') ){
                    q.push({newrow,newcol});
                    grid[newrow][newcol]=0;
                }

            }


        }

    }


    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        for(int row = 0 ; row < r ; row++){
            for(int col = 0 ; col < c ; col++ ){
                if(grid[row][col]=='1'){
                    bfs(grid,row,col);
                    count++;
                }
            }
        }
        return count;
        
    }
};