class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        if(n==0){return 0 ;}
        vector<vector<int>> dp(n, vector<int>(n));

        for(int l = 1 ; l<= n ; l++){

            for(int  i = 0 ; i+ l-1 < n; i++){
                int j = i+ l-1 ;

                if(i==j){
                    dp[i][j]= 1; 
                }
                else if(i+1==j){
                    dp[i][j] = (s[i]==s[j]) ? 2 : 1 ;
                }else{
                    dp[i][j] = (s[i]==s[j]) ? 2 + dp[i+1][j-1] : max(dp[i+1][j],dp[i][j-1]) ;
                }
            }

        }

        return dp[0][n-1];
        
    }
};