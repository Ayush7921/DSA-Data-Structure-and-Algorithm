class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses ;
        int n = prerequisites.size();
        unordered_map<int , vector<int>> adj;

        vector<int> indegree(V,0);

        for(int i = 0 ; i<n ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            indegree[v]++;
        }
        

        queue<int> q ;
        for(int i=0 ; i<V ; i++ ){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int count = 0 ;
        vector<int> ans ;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            ans.push_back(u);

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(count==V){
            return ans ;
        }else{
            return {};
        }
        
    }
};