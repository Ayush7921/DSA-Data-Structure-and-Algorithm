class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
       int n = stoneValue.size();
        
        // dp[i] stores the maximum score difference achievable 
        // by the current player starting from index i.
        // Size n + 1 ensures dp[n] safely returns 0 (the end of the game).
        vector<int> dp(n + 1, 0); 
        
        // Start from the end of the array and work backward
        for(int i = n - 1; i >= 0; i--) {
            int max_diff = INT_MIN;
            int sum = 0;
            
            // Try taking 1, 2, or 3 stones (j represents the offset)
            for(int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];
                
                // Maximize: Current stones taken MINUS the opponent's best future difference
                max_diff = max(max_diff, sum - dp[i + j + 1]);
            }
            
            dp[i] = max_diff;
        }
        
        // Evaluate the final difference from the starting position
        int diff = dp[0];
        
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};