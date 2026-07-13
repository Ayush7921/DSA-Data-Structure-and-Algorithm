class Solution {
public:

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

    int longestStrChain(vector<string>& words) {
        
    
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size(); 
        });
        vector<int > dp(words.size(),1);
        int maxlen= 1;
        for(int i =0 ; i<words.size() ; i++){
            for(int j =0 ; j<i ; j++){

                if(  words[i].size()==words[j].size()+1 && isSubsequence(words[j],words[i])  ){
                    
                    dp[i] = max(dp[i],dp[j]+1);
                    maxlen = max(maxlen ,dp[i] );
                }

            }
        }

        return maxlen;
    }
};