class Solution {
public:

    int dp[51][51][101] ;
    int N , M, K ;
    int Mod = 1e9 + 7 ;

    int solve ( int i , int sc , int max){
        if(i==N){
            if(sc == K){
                return 1 ; 
            }else{
            return 0 ;}
        }

        if(dp[i][sc][max]!= -1){

            return dp[i][sc][max];
        }
        int result =  0 ;

        for(int j = 1 ; j<= M ; j++){
            if(j>max){
                result = (result + solve(i+1,sc+1,j))% Mod;
            }else{

            result = (result + solve(i+1,sc,max)) % Mod;  }
        }

        return dp[i][sc][max] = result % Mod  ;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M= m;
        K= k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);

    }
};