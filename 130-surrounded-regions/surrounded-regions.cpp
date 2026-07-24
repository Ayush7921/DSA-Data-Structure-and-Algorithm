class Solution {
public:
    int tr;
    int tc;

    void dfs(vector<vector<char>>& board, int i, int j) {

        board[i][j]='S';


        static int delrow[] ={-1,0,1,0};
        static int delcol[] = {0,1,0,-1};

        for(int k = 0 ; k< 4 ; k++){
            int nr = i + delrow[k];
            int nc= j + delcol[k];

            if((nr>=0 && nr<tr) && (nc>=0 && nc<tc) && board[nr][nc]=='O'){
                dfs(board,nr,nc);
            }

        }

        
  
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; 

        tr = board.size();
        tc = board[0].size();

        int top = 0 ;
        int bottom = tr-1;
        int left = 0 ;
        int right = tc-1;

        for(int i = left ; i<=right ; i++){
            if(board[top][i]=='O'){
                dfs(board,top,i);
            }
        }

        for(int i = top ; i<=bottom ; i++){
            if(board[i][right]=='O'){
                dfs(board,i,right);
            }
        }

        for(int i = right ; i>=left ; i--){
            if(board[bottom][i]=='O'){
                dfs(board,bottom,i);
            }
        }

        for(int i = bottom ; i>=top ; i--){
            if(board[i][left]=='O'){
                dfs(board,i,left);
            }
        }


        for(int i =0 ; i< tr ; i++){
            for(int j = 0 ; j< tc ; j++){
                if(board[i][j]=='S'){
                    board[i][j]='O';
                }else if (board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }



        
    }
};