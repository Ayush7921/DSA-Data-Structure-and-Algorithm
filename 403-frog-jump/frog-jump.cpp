class Solution {
public:
    bool solve(vector<int>& stones,unordered_map<int,int >& mp ,int i , int k ,  vector<vector<int>>& dp){
        
        if (i==stones.size()-1){
            return true ;
        }
        if(dp[k][i]!=-1){
            return (bool)dp[k][i];
        }
        bool a=false;
        int currpos= stones[i] ; 
        for(int jump = k-1  ; jump<=k+1 ; jump++){

            if(jump>0 && mp.contains(currpos+jump)){
                int nextidx =mp[stones[i]+jump];
                a = a|| solve(stones , mp , nextidx , jump , dp);
            }
        }
        return dp[k][i] = (a==true)? 1 : 0 ;

    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(n==2){
            return (stones[1]==1);
        }

        if(stones[1]!=1){
            return (stones[1]==1);
        }

        unordered_map<int,int > mp;
        for(int i = 0 ; i< n;i++){
            mp[stones[i]]=i;
        }

        int k = *max_element(stones.begin(),stones.end());
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return solve(stones , mp , 1,1,dp);
        
    }
};