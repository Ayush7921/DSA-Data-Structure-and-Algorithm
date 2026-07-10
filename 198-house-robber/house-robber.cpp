class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if(n==1){return nums[0];}
        
        vector<int > dp(n);
        dp[n-1]=nums[n-1];
        dp[n-2]=nums[n-2];
        int maxresult=dp[n-1];
        for(int i = n-3 ; i>=0 ; i--)
        {
            dp[i]= nums[i] + maxresult;

            maxresult=max(maxresult,dp[i+1]);
        }

        return max(dp[0],dp[1]);
    }
};