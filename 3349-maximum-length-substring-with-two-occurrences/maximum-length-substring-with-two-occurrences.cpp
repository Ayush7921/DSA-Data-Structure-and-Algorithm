class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i= 0 ;
        int j = 0 ;
        int n = s.size();

        vector<int> v(26,0);
        int len = 0;

        while(j<n){

            v[s[j]-'a']++;

            while(v[s[j]-'a']>2){
                v[s[i]-'a']--;
                i++;
            }

            len = max(len,j-i+1);
            j++;

        }
        
        return len;
    }
};