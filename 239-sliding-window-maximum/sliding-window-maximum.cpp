class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k==1 || nums.size()==1){return nums;}
        
        deque<int> dq;
        vector<int> ans ;
        int j =0 ;
        int n = nums.size();
        int i =0;
        while(j<n){
            
            while(!dq.empty() && nums[j]>dq.back()){

                dq.pop_back();

            }
            dq.push_back(nums[j]);

            if(j-i+1==k){
                ans.push_back(dq.front());

                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};