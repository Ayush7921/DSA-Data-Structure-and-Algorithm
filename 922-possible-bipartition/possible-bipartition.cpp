class Solution {
public:
    vector<int> parent, Rank;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(Rank[a] < Rank[b])
            swap(a, b);

        parent[b] = a;

        if(Rank[a] == Rank[b])
            Rank[a]++;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for(auto &e : dislikes) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.resize(n + 1);
        Rank.assign(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(int u = 1; u <= n; u++) {

            if(adj[u].empty()) continue;

            int first = adj[u][0];

            for(int v : adj[u]) {

                if(find(u) == find(v))
                    return false;

                Union(first, v);
            }
        }

        return true;
    }
};