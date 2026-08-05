class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &e : times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        // Min-Heap using priority_queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> d(n + 1, INT_MAX);
        d[k] = 0;
        d[0] = 0; // Ignoring the 0th index
        pq.push({0, k});

        while(!pq.empty()){
            // Get the top element and immediately pop it
            auto it = pq.top();
            pq.pop();
            
            int di = it.first;
            int node = it.second;

            // LAZY DELETION: 
            // If we pull out an outdated, longer distance, just ignore it.
            if(di > d[node]) continue;

            for(auto &v : adj[node]){
                int adjnode = v.first;
                int weight = v.second;

                if(di + weight < d[adjnode]){
                    // No need to erase anything, just update and push
                    d[adjnode] = di + weight;
                    pq.push({d[adjnode], adjnode});
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++){
            if(d[i] == INT_MAX){
                return -1;
            }
        }

        // Renamed to max_time to prevent shadowing std::max
        int max_time = *max_element(d.begin(), d.end());
        return max_time;
    }
};