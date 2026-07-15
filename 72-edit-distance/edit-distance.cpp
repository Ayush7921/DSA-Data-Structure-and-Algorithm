class Solution {
public:
    int dp[501][501];

    int solve (string & s1 , string & s2 , int m , int n ){

        if(m==0 || n==0){
            return m+n ;
        }

        if(dp[m][n]!= -1){
            return dp[m][n];
        }

        if(s1[m-1]==s2[n-1]){
            return dp[m][n] = solve(s1,s2,m-1 ,n-1);
        }
            int insert = 1 + solve(s1,s2,m,n-1);
            int del = 1 + solve(s1,s2,m-1,n);
            int replace = 1 + solve(s1,s2,m-1,n-1);

            return dp[m][n]= min(insert ,min(del,replace) );
    }
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();

        memset(dp,-1,sizeof(dp));

        return solve(word1,word2,m,n);
    }
};