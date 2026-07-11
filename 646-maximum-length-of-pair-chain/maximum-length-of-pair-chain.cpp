class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
   
        if(n==1) return 1;
        sort(pairs.begin(), pairs.end());
        vector<int > dp(n,1);

        int maxresult = 1;

        for(int  i=0 ; i< n ; i++){
            for(int j = 0 ; j< i; j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]= max(dp[i],dp[j]+1);
                    maxresult = max(maxresult, dp[i]);
                }
            }
        }

        return maxresult;

    }
};