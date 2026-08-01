#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size; // Tracks the number of nodes in a component

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Standard union by size
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    // Returns the total number of bricks currently attached to the ceiling
    int getCeilingSize() {
        return size[find(0)]; 
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Helper to convert 2D coordinates to 1D index (reserving 0 for Ceiling)
        auto getIndex = [&](int r, int c) {
            return r * cols + c + 1;
        };
        
        // Step 1: Clone the grid and apply all hits to find the "End of Time" state
        vector<vector<int>> current_grid = grid;
        for (const auto& hit : hits) {
            current_grid[hit[0]][hit[1]] = 0;
        }
        
        DSU dsu(rows * cols + 1); // +1 for the Ceiling Node at index 0
        
        // Directions for checking neighbors (Up, Down, Left, Right)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Step 2: Build the DSU for the "End of Time" state
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (current_grid[r][c] == 1) {
                    int idx = getIndex(r, c);
                    if (r == 0) {
                        dsu.unite(0, idx); // Attach top row to Ceiling
                    }
                    // Connect to adjacent bricks (we only need to check Up and Left to avoid redundant checks)
                    if (r > 0 && current_grid[r - 1][c] == 1) {
                        dsu.unite(idx, getIndex(r - 1, c));
                    }
                    if (c > 0 && current_grid[r][c - 1] == 1) {
                        dsu.unite(idx, getIndex(r, c - 1));
                    }
                }
            }
        }
        
        vector<int> ans(hits.size(), 0);
        
        // Step 3: Rewind time - process hits in reverse order
        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0];
            int c = hits[i][1];
            
            // If there was no brick here originally, nothing falls
            if (grid[r][c] == 0) continue; 
            
            int prev_ceiling_size = dsu.getCeilingSize();
            int idx = getIndex(r, c);
            
            // Add the brick back
            current_grid[r][c] = 1; 
            
            // Connect to adjacent stable bricks
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && current_grid[nr][nc] == 1) {
                    dsu.unite(idx, getIndex(nr, nc));
                }
            }
            
            // If it's on the top row, connect to Ceiling
            if (r == 0) {
                dsu.unite(0, idx);
            }
            
            int new_ceiling_size = dsu.getCeilingSize();
            
            // If the ceiling size grew, bricks got re-attached!
            // Subtract 1 because the brick we just added (the "hit" brick) doesn't count as falling.
            if (new_ceiling_size > prev_ceiling_size) {
                ans[i] = new_ceiling_size - prev_ceiling_size - 1;
            }
        }
        
        return ans;
    }
};