class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prequisites) {
        int V = numCourses ;
        int n =prequisites.size();

        unordered_map<int,vector<int>> adj ;

        for(int i = 0 ; i< n ; i++){
            adj[prequisites[i][1]].push_back(prequisites[i][0]);
        }

        vector<int> indegree(V,0);

        for(int i = 0 ; i< n ; i++ ){
            indegree[prequisites[i][0]]++;
        }

        queue<int> q ; 
        for(int i = 0 ; i< V ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            count++;

            for(int &v : adj[u]){

                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }

                
            }
        }

        return (V==count);
    }
};