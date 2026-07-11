class Solution {
public:

    long long dp[100001][2];

    long long solve(vector<int>& nums,int i,bool flag,int n){

        if(i>=n)
            return 0;

        if(dp[i][flag]!=-1)
            return dp[i][flag];

        long long skip = solve(nums,i+1,flag,n);

        long long val = nums[i];

        if(!flag)
            val = -val;

        long long take = val + solve(nums,i+1,!flag,n);

        return dp[i][flag] = max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        memset(dp,-1,sizeof(dp));

        return solve(nums,0,1,nums.size());
    }
};