class Solution {
public:
    int findGCD(vector<int>& nums) {

        int maxelement = *max_element(nums.begin(),nums.end());
        int minelement = *min_element(nums.begin(),nums.end());

        return gcd(maxelement , minelement);

        
    }
};