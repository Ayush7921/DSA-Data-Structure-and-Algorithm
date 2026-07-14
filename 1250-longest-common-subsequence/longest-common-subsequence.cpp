class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1));

        for(int row = 0 ; row< m+1 ; row++){
            dp[row][0]=0;
        }

        for(int col = 0 ; col< n+1 ; col++){
            dp[0][col]=0;
        }

        for(int i = 1 ; i < m+1 ; i++){
            for(int j = 1 ; j< n+1 ; j++){

                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }

        }

        return dp[m][n];
    }
};