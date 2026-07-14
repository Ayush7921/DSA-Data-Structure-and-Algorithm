class Solution {
public:
    int dp[201][201][201];
    int N;
    int mod = 1e9 + 7;

    int solve(vector<int> &nums , int idx , int gcd1 , int gcd2){
        if(idx==N){
            if(gcd1==gcd2 && gcd1!=0){
                return 1;
            }
            return 0;
        }

        if(dp[idx][gcd1][gcd2]!=-1){
            return dp[idx][gcd1][gcd2];
        }

        int result = 0;
        result = result + solve(nums,idx+1, gcd1 , gcd2);

        int newgcd = (gcd1==0) ? nums[idx] : gcd(gcd1, nums[idx]);
        result = max(result  , (result + solve(nums ,idx+1 ,newgcd,gcd2))) % mod ;

        newgcd = (gcd2==0) ? nums[idx] : gcd(gcd2, nums[idx]);
        result = max(result  , (result + solve(nums ,idx+1,gcd1 , newgcd)) ) % mod;

        return dp[idx][gcd1][gcd2]= result % mod ;
    }
    int subsequencePairCount(vector<int>& nums) {
        
        N = nums.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(nums,0,0,0);
        
    }
};