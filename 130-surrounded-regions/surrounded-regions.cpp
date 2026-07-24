class Solution {
public:
    int tr;
    int tc;

    void bfs(vector<vector<char>>& board, int startRow, int startCol, vector<vector<bool>>& vis) {
        
        // Declare these locally! They will automatically destroy themselves when BFS finishes.
        queue<pair<int, int>> q;
        stack<pair<int, int>> st;
        bool touchesBoundary = false;

        q.push({startRow, startCol});
        st.push({startRow, startCol});
        vis[startRow][startCol] = true;

        // Arrays are much faster than vectors, and should be declared outside the while loop
        int deltarow[] = {-1, 0, 1, 0};
        int deltacol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + deltarow[i];
                int ncol = c + deltacol[i];

                if (nrow >= 0 && nrow < tr && ncol >= 0 && ncol < tc && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    
                    if (nrow == 0 || nrow == tr - 1 || ncol == 0 || ncol == tc - 1) {
                        touchesBoundary = true;
                    }

                    vis[nrow][ncol] = true; // Fixed typo
                    q.push({nrow, ncol});
                    st.push({nrow, ncol});
                }
            }
        }

        // If it touched the boundary, we just exit. 
        // C++ automatically wipes 'st' from memory here!
        if (touchesBoundary) {
            return;
        }

        // Otherwise, flip everything in the stack to 'X'
        while (!st.empty()) {
            int r = st.top().first;
            int c = st.top().second;
            st.pop();
            board[r][c] = 'X';
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; // Always good practice to protect against empty grids

        tr = board.size();
        tc = board[0].size();

        vector<vector<bool>> vis(tr, vector<bool>(tc, false));

        for (int i = 1; i < tr - 1; i++) {
            for (int j = 1; j < tc - 1; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    // Start BFS, passing only the board, coordinates, and visited array
                    bfs(board, i, j, vis);
                }
            }
        }
    }
};