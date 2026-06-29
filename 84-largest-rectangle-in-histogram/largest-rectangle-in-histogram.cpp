class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s ;
        vector<int> left(n,-1);

        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                left[i]=s.top();
            }
            s.push(i);
        }

        s=stack<int>();

        vector<int> right(n,n);

        for(int j = n-1 ; j>=0 ; j--){
            while(!s.empty() && heights[j] <= heights[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                right[j]=s.top();
            }
            s.push(j);
        }
        int ans = INT_MIN;
        for(int k = 0 ; k< n ; k++){
            int l=heights[k];
            int b=right[k]-left[k]-1;

            ans =max( ans ,max(heights[k] , l*b));
        }

        return ans;

        
    }
};