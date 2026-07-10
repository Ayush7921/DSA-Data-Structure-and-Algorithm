class Solution {
public:
    int solve(vector<int>nums,vector<int> &dp , int i , int n){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int steal = nums[i] + solve(nums,dp,i+2,n);
        int skip = solve(nums,dp,i+1,n);

        return dp[i]=max(steal,skip);
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> v(101,-1);

        return solve(nums,v,0,n);
        
     
    }
};