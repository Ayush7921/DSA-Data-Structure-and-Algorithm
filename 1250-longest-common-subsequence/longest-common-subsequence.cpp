class Solution {
public:
    int dp[1001][1001];
    int solve(string &text1 , string &text2 , int i , int j ){
        if(i>=text1.size() || j>= text2.size()){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result = 0;
        if(text1[i]==text2[j]){
            result = 1 + solve(text1 , text2 , i+1 , j+1);
        }else
        result = max(solve(text1,text2,i+1,j) , solve(text1 , text2 , i , j+1));

        return dp[i][j] = result ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp,-1,sizeof(dp));

        return solve (text1,text2,0,0);

    }
};