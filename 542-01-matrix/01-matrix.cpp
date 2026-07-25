class Solution {
public:
    int tr;
    int tc ;
    const int deltarow[4] = {-1,0,1,0};
    const int deltacol[4] = {0,1,0,-1};

    void bfs( vector<vector<int>>& mat ){
        queue<pair<int,int>> q ;

        for(int i = 0 ; i<tr ; i++){
            for(int j = 0 ; j < tc ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(int k = 0 ; k< 4 ; k++){

                int nr = i + deltarow[k];
                int nc = j + deltacol[k];

                if((nr>=0 && nr < tr) && (nc>=0 && nc<tc) && (mat[nr][nc]==-1)){
                    mat[nr][nc]= 1+ mat[i][j];
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        tr = mat.size();
        tc= mat[0].size();

        bfs(mat);
        return mat;
        
    }
};