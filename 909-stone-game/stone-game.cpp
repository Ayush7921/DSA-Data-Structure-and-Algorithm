class Solution {
public:

    // int dp[501][501] ;
    // int solve(int i , int j , vector<int>& piles )
    // {
    //     if(i==j) return piles[i];

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     int t1 = piles[i] - solve(i+1,j,piles);
    //     int t2 = piles[j] - solve(i,j-1,piles);


    //     return dp[i][j]=max(t1,t2);
    // }
    bool stoneGame(vector<int>& piles) {

        // memset(dp,-1,sizeof(dp));
        // return (solve(0,piles.size()-1,piles)>0);

        return true;
    }
};