class Solution {
public:
    void rotate(vector<vector<int>>& m) {

        //transpose 

        for(int row = 0 ; row< m.size() ; row++){
            for(int col = row +1 ; col < m[0].size();col++){
                swap(m[row][col],m[col][row]);
            }
        }

        for(int row = 0 ; row < m.size();row++){
            reverse(m[row].begin(),m[row].end());
        }
        
    }
};