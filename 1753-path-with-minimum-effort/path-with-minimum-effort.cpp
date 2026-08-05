class Solution {
public:
    typedef pair<int , pair<int,int>> P;
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int tr = heights.size();
        int tc = heights[0].size();

        priority_queue<P, vector<P>, greater<P>> pq ;

        // FIX 1: Initialize all distances to INT_MAX
        vector<vector<int>> temp(tr, vector<int>(tc, INT_MAX));

        temp[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int current_effort = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second ;
            pq.pop();

            // Optimization: If we pop the destination, we are guaranteed it's the minimum effort path
            if(i == tr - 1 && j == tc - 1) {
                return current_effort;
            }

            // Lazy Deletion: skip outdated pairs in the priority queue
            if(current_effort > temp[i][j]) continue;

            for(auto &d : dir ){
                int r = i + d[0];
                int c = j + d[1];

                // FIX 2: Replaced the ';' with '&&'
                if(r >= 0 && r < tr && c >= 0 && c < tc){
                    
                    // The effort to reach neighbor is the max of the path so far, and the jump to neighbor
                    int new_effort = max(current_effort, abs(heights[i][j] - heights[r][c]));
                    
                    // FIX 3: Compare against the neighbor's current best effort (temp[r][c])
                    if(new_effort < temp[r][c]){
                        temp[r][c] = new_effort;
                        pq.push({new_effort, {r, c}});
                    }
                }
            }
        }

        return 0; // Fallback (should not be reached if grid is valid)
    }
};