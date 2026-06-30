class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int count = 0;
        int i =0;
        int j =0 ;

        while(j<n){
            mp[s[j]]++;
            
            if(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count=count + (s.size()-j);
                mp[s[i]]--;
                i++;
                while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count= count + (s.size()-j);
                mp[s[i]]--;
                i++;  }

            }

            j++;



        }
        return count ;
    }
};