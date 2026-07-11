class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sumAdd = 0; // Tracks the state where the last operation was an addition
        long long sumSub = 0; // Tracks the state where the last operation was a subtraction

        for (int x : nums) {
            long long tempAdd = max(sumAdd, sumSub + x);
            long long tempSub = max(sumSub, sumAdd - x);
            
            sumAdd = tempAdd;
            sumSub = tempSub;
        }

        return max(sumAdd, sumSub);
    }
};