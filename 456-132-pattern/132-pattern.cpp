class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2){
            return false ;
        }

        stack<int > s;
        
        int num3 = INT_MIN;
        for(int i =n-1 ; i>=0 ; i-- ){
           
            if(num3>nums[i]){
                return true ;
            }

            while(!s.empty() && s.top()< nums[i]){
                num3=s.top();
                s.pop();
            }

            s.push(nums[i]);
            
        }
        return false;

    }
};