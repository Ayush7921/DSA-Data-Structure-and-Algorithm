class Solution {
public:
    // FIX 1: Pass topoitems by reference '&'
    bool dfs(unordered_map<int, vector<int>>& adj, int u, vector<int>& visitems, vector<int>& topoitems) {
        visitems[u] = 1;

        for (int v : adj[u]) {
            if (visitems[v] == 0) {
                // FIX 2: Actually catch the cycle if it bubbles up
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

        // 2. Build Item Graph
        unordered_map<int, vector<int>> itemAdj;
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
        // FIX 3: Reverse to get correct Topo Order
        reverse(topoitems.begin(), topoitems.end()); 

        // 4. Build Group Graph
        unordered_map<int, vector<int>> groupAdj;
        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                int group_u = group[u];
                int group_v = group[v];
                // FIX 4: Only connect if they are in different groups
                if (group_u != group_v) {
                    groupAdj[group_u].push_back(group_v);
                }
            }
        }

        // 5. Topo Sort Groups
        // FIX 5: Total number of groups is 'm'
        vector<int> visgroups(m, 0); 
        vector<int> topogroups;
        for (int i = 0; i < m; i++) {
            if (visgroups[i] == 0 && dfs(groupAdj, i, visgroups, topogroups)) {
                return {}; // Cycle detected in groups
            }
        }
        // FIX 3 again: Reverse to get correct Topo Order
        reverse(topogroups.begin(), topogroups.end());

        // 6. Group the sorted items
        // We reuse itemAdj to map: group_id -> list of items in that group
        itemAdj.clear(); 
        for (int item : topoitems) {
            int grp = group[item];
            itemAdj[grp].push_back(item);
        }

        // 7. Build final answer
        vector<int> ans;
        for (int grp : topogroups) {
            for (int item : itemAdj[grp]) {
                ans.push_back(item);
            }
        }

        return ans;
    }
};