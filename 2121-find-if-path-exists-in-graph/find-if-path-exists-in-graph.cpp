class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int u, int d, vector<bool>& vis) {
        vis[u] = true;

        for (int& v : adj[u]) {
            if (v == d) {
                return true;
            } else if (!vis[v]) {
                if (dfs(adj, v, d, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Base case: already at the destination
        if (source == destination) {
            return true;
        }

        // Optimization: Use a vector of vectors instead of an unordered_map
        vector<vector<int>> adj(n);

        // Build the graph using a cleaner range-based for loop
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<bool> vis(n, false);
        
        // Fix: start the DFS at 'source', not '0'
        return dfs(adj, source, destination, vis);
    }
};