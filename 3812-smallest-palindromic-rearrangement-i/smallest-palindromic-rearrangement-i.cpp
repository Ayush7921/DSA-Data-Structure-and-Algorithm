class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> present(26, 0);

        for(char c : s)
            present[c - 'a']++;

        int n = s.size();
        string str(n, ' ');

        int i = 0;
        int j = n - 1;

        for(int k = 0; k < 26; k++)
        {
            while (present[k] >= 2) {
                str[i++] = char(k + 'a');
                str[j--] = char(k + 'a');
                present[k] -= 2;
            }
        }

        for (int k = 0; k < 26; k++) {
            if (present[k] == 1) {
                str[i] = char(k + 'a');   // here i == j
                break;
            }
        }

        return str;
    }
};