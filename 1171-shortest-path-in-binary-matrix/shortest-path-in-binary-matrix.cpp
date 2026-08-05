class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        if(n==1){
            return 1 ;
        }

        queue<pair<int, int>> q ;
        q.push({0,0});
        grid[0][0]=1;

        int ans = 1 ;

        while(!q.empty()){
            int sz = q.size();

            for(int k = 0 ; k< sz ; k++){
                int i = q.front().first;
                int j = q.front().second ;
                q.pop();

                for(int dr = -1 ; dr <=1 ; dr++){
                    for(int dc = -1 ; dc <=1 ; dc++){
                        int r = i + dr ;
                        int c = j + dc ;

                        if( r >=0 && r < n && c >=0 && c<n && grid[r][c]==0){
                            if(r==n-1 && c==n-1){
                                return ans+1;
                            }

                            q.push({r,c});
                            grid[r][c]=1;
                        }
                    }
                }

            }
            ans++;
            
        }

        return -1 ;
        

    }
};