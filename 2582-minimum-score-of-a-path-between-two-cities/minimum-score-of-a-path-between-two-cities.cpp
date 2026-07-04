class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int ans = INT_MAX;

    void dfs(int node) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            int nei = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[nei]) {
                dfs(nei);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        adj.resize(n + 1);
        vis.assign(n + 1, 0);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        dfs(1);

        return ans;
    }
};