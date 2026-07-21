class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0; // Mark as visited

        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        int area = 1; // Start counting from the initial node

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {          
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];

                if (newcol >= 0 && newcol < m && newrow >= 0 && newrow < n && grid[newrow][newcol] == 1) {
                    q.push({newrow, newcol});
                    grid[newrow][newcol] = 0;
                    area += 1; // Increment area for every valid neighbor found
                }
            }
        }
        
        return area; // Return the total area of this island
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                if (grid[row][col] == 1) {
                    // Update max area directly from the return value
                    ans = max(ans, bfs(grid, row, col));
                }
            }
        }
        return ans;
    }
};