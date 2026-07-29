class Solution {
private:
    // Maths function to calculate combinations (nCr) safely without overflow
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1);
            res /= i;
            if (res > 2e9) return 2e9 + 1; // Cap to prevent overflow
        }
        return res;
    }

    // Function to calculate total unique permutations for a given frequency map
    long long getPerms(vector<int>& freq) {
        long long perms = 1;
        int total_len = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                total_len += freq[i];
                perms *= nCr(total_len, freq[i]);
                if (perms > 2e9) perms = 2e9 + 1; // Cap safely above standard 'k' limits
            }
        }
        return perms;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int mid = n / 2;
        
        // 1. Count frequencies of the left half
        vector<int> freq(26, 0);
        for(int i = 0; i < mid; i++) {
            freq[s[i] - 'a']++;
        }
        
        // 2. Check if k is mathematically possible
        long long total_perms = getPerms(freq);
        if (k > total_perms) {
            return ""; // k-th permutation doesn't exist
        }
        
        // 3. Build the k-th permutation directly character by character
        string left_half = "";
        for (int i = 0; i < mid; i++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] > 0) {
                    
                    // Temporarily place this character and calculate remaining permutations
                    freq[c]--;
                    long long p = getPerms(freq);
                    
                    if (k <= p) {
                        // The k-th permutation is definitely in this branch
                        left_half += (char)(c + 'a');
                        break; // Move to the next position in the string
                    } else {
                        // Skip this branch and reduce k
                        k -= p;
                        freq[c]++; // Backtrack and try the next character
                    }
                }
            }
        }
        
        // 4. Mirror the newly built left half onto the original string
        for(int i = 0; i < mid; i++) {
            s[i] = left_half[i];
            s[n - i - 1] = s[i];
        }
        
        return s;
    }
};