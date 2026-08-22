class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<int> row;
        vector<int> col;

        int tr = matrix.size();
        int tc = matrix[0].size();

        for(int i = 0 ; i<tr ; i++){
            for(int j = 0 ; j< tc ; j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int r : row){
            for(int i = 0 ; i < tc ; i++ ){
                if(matrix[r][i]==0){
                    continue;
                }

                matrix[r][i]=0;
            }
        }

        for(int c : col){
            for(int i = 0 ; i < tr ; i++ ){
                if(matrix[i][c]==0){
                    continue;
                }

                matrix[i][c]=0;
            }
        }
        
    }
};