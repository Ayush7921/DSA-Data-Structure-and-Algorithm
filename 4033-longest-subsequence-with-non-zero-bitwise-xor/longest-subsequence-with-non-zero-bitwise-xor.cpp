class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorresult = 0 ;
        int totalc0= 0 ;

        for(int x : nums){
            xorresult=xorresult^x;
            if(x==0){
                totalc0++;
            }
        }

        if(xorresult!=0){
            return nums.size();
        }

        if(totalc0==nums.size()){
            return 0;
        }

        return nums.size()-1;
    }
};