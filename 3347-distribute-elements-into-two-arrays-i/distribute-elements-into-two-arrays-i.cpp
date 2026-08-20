class Solution {
public:
    vector<int> resultArray(vector<int>& nums) { 
        int n = nums.size();
        
        vector<int> result;
        int a = nums[0];
        int b = nums[1];
        nums[1]=-nums[1];

        for(int i =2 ; i< n ; i++ ){
            if(a>b){
                a=nums[i];
            }else{
                b=nums[i];
                nums[i]=-nums[i];
            }
        }

        //add 1st array
        
        for(int i =0 ; i< n ; i++ ){
            if(nums[i]>0){
                result.push_back(nums[i]);
            }
        }

        // for 2nd array
        
        for(int i =0 ; i< n ; i++ ){
            if(nums[i]<0){
                result.push_back(-nums[i]);
            }
        }

        return result ;
        

    }
};