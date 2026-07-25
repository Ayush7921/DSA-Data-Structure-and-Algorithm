class Solution {
public:
    int tr;
    int tc ;
    const int deltarow[4] = {-1,0,1,0};
    const int deltacol[4] = {0,1,0,-1};

    void bfs( vector<vector<int>>& isWater ){
        queue<pair<int,int>> q ;

        for(int i = 0 ; i<tr ; i++){
            for(int j = 0 ; j < tc ; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                }else{
                    isWater[i][j]=-1;
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

                if((nr>=0 && nr < tr) && (nc>=0 && nc<tc) && (isWater[nr][nc]==-1)){
                    isWater[nr][nc]= 1+ isWater[i][j];
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        tr = isWater.size();
        tc= isWater[0].size();

        bfs(isWater);
        return isWater;
    }
};