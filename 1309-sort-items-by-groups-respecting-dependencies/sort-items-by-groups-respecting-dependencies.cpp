class Solution {
public:
    // OPTIMIZATION: Now taking a vector of vectors instead of an unordered_map
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& visitems, vector<int>& topoitems) {
        visitems[u] = 1;

        for (int v : adj[u]) {
            if (visitems[v] == 0) {
                if (dfs(adj, v, visitems, topoitems)) {
                    return true;
                }
            } else if (visitems[v] == 1) {
                return true; // Cycle found
            }
        }

        topoitems.push_back(u);
        visitems[u] = 2;
        return false;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // 1. Assign unique groups to -1
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m;
                m++;
            }
        }

        // 2. Build Item Graph (Optimized: Direct memory access with vector)
        vector<vector<int>> itemAdj(n);
        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                itemAdj[u].push_back(v);
            }
        }
        
        // 3. Topo Sort Items
        vector<int> visitems(n, 0);
        vector<int> topoitems;
        for (int i = 0; i < n; i++) {
            if (visitems[i] == 0 && dfs(itemAdj, i, visitems, topoitems)) {
                return {}; // Cycle detected in items
            }
        }
        reverse(topoitems.begin(), topoitems.end()); 

        // 4. Build Group Graph (Optimized: Sized to exactly 'm' groups)
        vector<vector<int>> groupAdj(m);
        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                int group_u = group[u];
                int group_v = group[v];
                
                if (group_u != group_v) {
                    groupAdj[group_u].push_back(group_v);
                }
            }
        }

        // 5. Topo Sort Groups
        vector<int> visgroups(m, 0); 
        vector<int> topogroups;
        for (int i = 0; i < m; i++) {
            if (visgroups[i] == 0 && dfs(groupAdj, i, visgroups, topogroups)) {
                return {}; // Cycle detected in groups
            }
        }
        reverse(topogroups.begin(), topogroups.end());

        // 6. Group the sorted items 
        // (Optimized: A 2D vector sized to 'm' is much faster than clearing an old map)
        vector<vector<int>> groupToItems(m);
        for (int item : topoitems) {
            int grp = group[item];
            groupToItems[grp].push_back(item);
        }

        // 7. Build final answer
        vector<int> ans;
        for (int grp : topogroups) {
            for (int item : groupToItems[grp]) {
                ans.push_back(item);
            }
        }

        return ans;
    }
};