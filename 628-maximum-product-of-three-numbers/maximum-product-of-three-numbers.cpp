class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int m1 = INT_MIN;
        int m2 = INT_MIN;
        int m3 = INT_MIN;
        int s1 = INT_MAX;
        int s2 = INT_MAX;   


        for(int i = 0 ; i< nums.size() ; i++){
            if(m1<nums[i])
            {
                m3 = m2 ;
                m2 = m1 ;
                m1 = nums[i];

            }
            else if (m2<nums[i])
            {
                m3 = m2 ;
                m2 = nums[i];
            }
            else if(m3 < nums[i])
            {
                m3 = nums[i];
            }


            if(s1>nums[i]){
                s2=s1;
                s1=nums[i];
            }else if(s2>nums[i]){
                s2 = nums[i];
            }
        }

        int op1 = s1*s2*m1;
        int op2 = m1*m2*m3 ;

        return max(op1,op2);     
    }
};