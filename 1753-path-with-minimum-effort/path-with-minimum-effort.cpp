class Solution {
public:

    typedef pair<int , pair<int,int>> P;
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int tr= heights.size();
        int tc = heights[0].size();

        priority_queue<P,vector<P>, greater<P>> pq ;

        vector<vector<int>> temp(tr,vector<int>(tc,INT_MAX));

        temp[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second ;
            pq.pop();

            for(auto &d : dir ){
                int r = i + d[0];
                int c = j + d[1];

                if(r>=0 && r < tr && c >=0 && c < tc){
                    if(max(temp[i][j],abs(heights[i][j]-heights[r][c]))< temp[r][c]){
                        temp[r][c] = max(temp[i][j],abs(heights[i][j]-heights[r][c]));
                        pq.push({temp[r][c],{r,c}});
                    }
                }
            }

        }

        return temp[tr-1][tc-1];

    }
};