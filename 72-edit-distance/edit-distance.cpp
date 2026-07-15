class Solution {
public:
    // int dp[501][501];

    // int solve (string & s1 , string & s2 , int m , int n ){

    //     if(m==0 || n==0){
    //         return m+n ;
    //     }

    //     if(dp[m][n]!= -1){
    //         return dp[m][n];
    //     }

    //     if(s1[m-1]==s2[n-1]){
    //         return dp[m][n] = solve(s1,s2,m-1 ,n-1);
    //     }
    //         int insert = 1 + solve(s1,s2,m,n-1);
    //         int del = 1 + solve(s1,s2,m-1,n);
    //         int replace = 1 + solve(s1,s2,m-1,n-1);

    //         return dp[m][n]= min(insert ,min(del,replace) );
    // }
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i = 0 ; i<= m ; i++){
            for(int j= 0 ; j<= n ; j++){

                if(i==0 || j==0 ){
                    dp[i][j]=i+j ;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i-1][j] , min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};