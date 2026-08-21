class Solution {
public:
    bool check(vector<int>& nums) {
        int  breakpoints = 0 ;
        for(int i = 1 ; i< nums.size(); i++){
            if(nums[i]<nums[i-1]){
                breakpoints++;
            }
            if(breakpoints>=2){
                break ;
            }
        }
        
        if(breakpoints == 0) return true;

        if(breakpoints >=2 ) return false ;

        return nums[0] >= nums[nums.size()-1];


    }
};