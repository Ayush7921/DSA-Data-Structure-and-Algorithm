class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int freq = 1 ;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]==me){
                freq++;
            }else if(freq == 0){
                me = nums[i];
                freq++;
            }else{
                freq--;
            } 
        }

        return me ;

    }
};