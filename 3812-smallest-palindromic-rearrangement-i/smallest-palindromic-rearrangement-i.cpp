class Solution {
public:
    string smallestPalindrome(string s) {

        int present[26] = {0};
        int n = s.size();

        for(int i = 0; i < n/2; i++){
            present[s[i] - 'a']++;
        }

        int idx = 0;

        for(int i = 0; i < 26; i++){
            while(present[i] > 0){
                s[idx++] = (i + 'a');
                present[i]--;
            }
        }

        for(int i = 0; i < n/2; i++)
        {
            s[n - i - 1] = s[i];
        }

        return s;
    }
};