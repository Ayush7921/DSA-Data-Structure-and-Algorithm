class Solution {
public:
    int dp[1001][1001];

    bool ispalindrome(string &s , int i , int j ){
        if(i>=j){
            return true ;
        }
        
        if(dp[i][j]!=-1){ return dp[i][j] ; }
        if(s[i]==s[j]){
            return dp[i][j] = ispalindrome(s,i+1,j-1);
        }

        return dp[i][j]= false ;
    }


    int countSubstrings(string s) {
        int n = s.size();

        memset(dp,-1,sizeof(dp));

        int result=0;

        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j< n ; j++){

                if(ispalindrome(s,i,j)){
                    result+=1;
                }
            }
        }

        return result ;
    }
};