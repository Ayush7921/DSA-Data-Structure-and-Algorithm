class Solution {
public:
    int dp[21][21];
    int solve(int i , int j , vector<int >&nums){
        if(i==j) return nums[i];
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int takefirst = nums[i] - solve(i+1,j,nums);
        int takelast = nums[j]-solve(i, j-1,nums);

        return dp[i][j]=max(takefirst,takelast);

    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        return (solve(0,nums.size()-1,nums)>=0);
    }
};