class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        const int MAXXOR = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXXOR, false));

        dp[0][0] = true;

        for (int t = 0; t < 3; t++) {

            for (int xr = 0; xr < MAXXOR; xr++) {

                if (!dp[t][xr]) continue;

                for (int x : nums) {
                    dp[t + 1][xr ^ x] = true;
                }
            }
        }

        int ans = 0;

        for (int xr = 0; xr < MAXXOR; xr++) {
            if (dp[3][xr]) ans++;
        }

        return ans;
    }
};