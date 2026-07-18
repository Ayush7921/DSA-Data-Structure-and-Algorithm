class Solution {
public:
    bool solve(vector<int>& stones, unordered_map<int,int>& mp, int i, int k, vector<vector<int>>& dp) {
        
        // Base case: Reached the end
        if (i == stones.size() - 1) {
            return true;
        }
        
        // Return memoized result
        if (dp[k][i] != -1) {
            return dp[k][i];
        }
        
        int currpos = stones[i]; 
        
        // Try all 3 jumps
        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump > 0 && mp.contains(currpos + jump)) {
                int nextidx = mp[currpos + jump];
                
                // EARLY EXIT: If this path works, return immediately
                if (solve(stones, mp, nextidx, jump, dp)) {
                    return dp[k][i] = 1;
                }
            }
        }
        
        // If no jumps worked, mark as false
        return dp[k][i] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // The frog must be able to reach the first stone
        if (stones[1] != 1) {
            return false;
        }

        // Map for O(1) lookups
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        // Safe DP size: Max jump size is n, max index is n-1
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        
        return solve(stones, mp, 1, 1, dp);
    }
};