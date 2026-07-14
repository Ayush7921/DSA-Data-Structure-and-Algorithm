class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> dp(n , 1) ;
        vector<int> prev(n , -1);

        int maxindex= 0;
        int maxlen = 1 ;

        for (int i = 1 ; i< n ; i++){
            for(int j =0 ;j< i ; j++){

                if(nums[i] % nums[j] == 0){

                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }

                    if(dp[i]>maxlen){
                        maxlen=dp[i];
                        maxindex = i;
                    }
                }
            }
        }

        vector<int> ans ;

        while(maxindex != -1){
            ans.push_back(nums[maxindex]);
            maxindex = prev[maxindex];
        }

        return ans ;        
    }
};