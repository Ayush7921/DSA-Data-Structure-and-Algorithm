class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1=NULL;
        int count1=0;
        int maj2=INT_MIN;
        int count2=0;

        vector<int> ans;

        for(int i =0 ; i<nums.size() ;i++){

            if(nums[i]==maj1 ){
                count1++;
            }
            else if(nums[i]==maj2){
                count2++;
            }
            else if(count1==0){
                maj1=nums[i];
                count1++;
            }
            else if(count2==0){
                maj2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }


        if(count(nums.begin(), nums.end(), maj1)> nums.size()/3){
            ans.push_back(maj1);
        }
        if(count(nums.begin(), nums.end(), maj2)> nums.size()/3){
            ans.push_back(maj2);
        }
        return ans;
    }
};