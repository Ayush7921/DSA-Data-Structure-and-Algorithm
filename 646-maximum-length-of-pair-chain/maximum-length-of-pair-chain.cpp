class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs,int idx ,int prev, int n){
        if(idx>=n){
            return 0;
        }

        if(dp[idx][prev+1]!=-1 ){
            return dp[idx][prev+1];
        }

        int take =0;
        if(prev==-1){
            take = 1 + solve(pairs , idx+1 , idx , n );
        }else{
            if(pairs[idx][0]>pairs[prev][1]){
                take = 1 + solve(pairs , idx+1 , idx , n);
            }

        }

        int skip = solve(pairs , idx +1 , prev , n);

        return dp[idx][prev+1]=max(skip,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
   
        if(n==1) return 1;
        sort(pairs.begin(), pairs.end());
        
        memset(dp,-1,sizeof(dp));

        return solve(pairs , 0 , -1, n);

        
    }
};