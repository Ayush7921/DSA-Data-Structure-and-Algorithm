class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e  : times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v,wt});
        }

        set<pair<int,int >>st;
        vector<int> d(n+1,INT_MAX);
        d[k]=0;
        d[0]=0;
        st.insert({0,k});

        while(!st.empty()){
            auto it = st.begin();
            int di = it->first;
            int node = it->second ;
            st.erase(it);

            for(auto &v : adj[node]){
                int adjnode = v.first;
                int weight = v.second ;

                if(di + weight < d[adjnode]){
                    if(d[adjnode] != INT_MAX){
                        st.erase({d[adjnode],adjnode});
                    }
                    d[adjnode]=di+weight;
                    st.insert({d[adjnode],adjnode});
                }
            }
        }
        
            for(int i = 1 ; i< n+1 ; i++){
                if(d[i]==INT_MAX){
                    return -1;
                }
            }

            int max = *max_element(d.begin(),d.end());
            return max;
        
    }
};