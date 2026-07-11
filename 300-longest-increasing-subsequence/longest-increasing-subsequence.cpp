class Solution {
public:
    int solve (vector<int >& nums , vector<vector<int> >& dp,int  idx, int prev,int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take = 0;

        if(prev==-1 || nums[prev]<nums[idx]){
            take = 1 + solve(nums,dp ,idx+1,idx,n);
        }

        int skip = solve(nums,dp ,idx+1,prev,n);
        return dp[idx][prev+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        if(n==1) return 1;

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve (nums ,dp,0,-1,n);
    }
};