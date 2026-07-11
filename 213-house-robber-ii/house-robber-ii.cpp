class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1){return nums[0];}
        vector <int> dp(n+1);

        dp[0]=0;
        for(int i = 1; i<=n-1;i++){
            int steal = nums[i-1] + ((i-2>=0) ? dp[i-2] : 0);
            int skip = dp[i-1];

            dp[i]= max(steal,skip);
        }
        int result1 = dp[n-1];

        dp.clear();
        dp[0]=0;
        dp[1]=0;
        for(int i = 2; i<=n;i++){
            int steal = nums[i-1] + ((i-2>=0) ? dp[i-2] : 0);
            int skip = dp[i-1];

            dp[i]= max(steal,skip);
        }
        int result2 = dp[n];


        return max(result1,result2);

    }
};