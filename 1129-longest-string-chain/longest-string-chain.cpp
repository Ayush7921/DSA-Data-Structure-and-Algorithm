class Solution {
public:
    int dp[1001][1001];

    bool isSubsequence(string &s1, string &s2) {
        int i = 0; 
        int j = 0; 
    
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++; 
            }
            j++; 
    }
        return i == s1.length();
    }
    
    int solve(vector<string>& words , int i , int p , int n ){
        if(i>=n){
            return 0;
        }

        if(dp[i][p+1]!=-1){
            return dp[i][p+1];
        }
        
        int len = solve (words , i+1 , p , n); 
        if(p==-1 || words[i].size()==words[p].size() +1 && isSubsequence(words[p],words[i])){

            len = max(len , 1 + solve(words , i+1 , i , n));

        }

        return dp[i][p+1]= len ; 
    }

    int longestStrChain(vector<string>& words) {
        
        memset(dp,-1 , sizeof(dp));
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size(); 
        });
        return solve(words,0,-1,words.size());
    }
};