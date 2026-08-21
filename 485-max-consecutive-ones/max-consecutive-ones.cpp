class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxans = 0 ;
        int currsize = 0 ;

        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i]==1){
                currsize++;
                maxans=max(maxans,currsize);
            }else{
                currsize=0;
            }
        }

        return maxans;
        
    }
};