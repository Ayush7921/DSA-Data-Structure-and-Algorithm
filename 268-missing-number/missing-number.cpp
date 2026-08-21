class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //xor solution

        int ans = 0 ;
        int n = nums.size();

        for(int i = 0 ; i< n ; i++){
            ans = ans ^ i ^ nums[i] ;
        }

        return ans ^n ;
    }
};