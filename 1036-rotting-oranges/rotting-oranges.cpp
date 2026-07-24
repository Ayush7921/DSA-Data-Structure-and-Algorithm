class Solution {
public:
    int tr;
    int tc ;

    const int deltarow[4] = {-1,0,1,0};
    const int deltacol[4] = {0,1,0,-1};

    int bfs(vector<vector<int>>& grid){
        queue<pair<int , int>> q ;

        for(int i = 0 ; i<tr ; i++){
            for(int j = 0 ; j<tc ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count = -1 ;

        while(!q.empty()){

            int sz = q.size();

            for(int a = 0 ; a< sz ; a++){
                int i= q.front().first;
                int j = q.front().second;
                q.pop() ;

                for(int k = 0 ; k< 4 ; k++){

                    int nr =  i + deltarow[k];
                    int nc = j + deltacol[k];

                    if((nr>=0 && nr<tr) && (nc>=0 && nc<tc) && grid[nr][nc]==1){
                        grid[nr][nc]=3;
                        q.push({nr,nc});
                    }
                }

            }
            count++;

        }
        
        return count;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        if (grid.empty()) return -1; 

        tr = grid.size();
        tc = grid[0].size();

        int ans = max(0,bfs(grid));
        int count1 =0;

        for(int i = 0 ; i<tr ; i++){
            for(int j = 0 ; j<tc ; j++){
                if(grid[i][j]==1){
                    count1+=1;
                }
            }
        }

        if(count1==0){
            return ans ;
        }else {
            return -1;
        }
   }
};