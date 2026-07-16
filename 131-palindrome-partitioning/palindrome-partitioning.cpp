class Solution {
public:
    void solve(string s ,int i , vector<vector<bool>> & dp ,vector<vector<string>> &result  , vector<string> &currstr){
        if(i==s.length()){
            result.push_back(currstr);
            return;
        }

        for(int j = i ; j< s.size(); j++){
            if(dp[i][j]==true ){
                currstr.push_back(s.substr(i,j-i+1));
                solve(s , j+1 , dp,result , currstr);
                currstr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n));       
        for(int L = 1 ; L <= n ; L++){

            for(int i = 0 ; i+L-1<n ; i++){
                int j = i+L-1;

                if(i==j){
                    dp[i][i]= true;
                }
                else if(i+1==j){
                    dp[i][j] = (s[i]==s[j]) ;
                }else{
                    dp[i][j] = ((s[i]==s[j]) && (dp[i+1][j-1]));
                }
            }
        }

        vector<vector<string>> result ;
        vector<string> currstr ;

        solve(s,0,dp , result , currstr);

        return result ;

    }
};