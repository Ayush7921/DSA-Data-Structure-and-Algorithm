class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        int s = *min_element(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> look(m-s+1,-1);
        vector<int> ans ;

        for(int i = 0 ; i< n ; i++){
            look[nums[i]-s]=1;
        }

        for(int i = 0 ; i< look.size()-1 ; i++){
            if(look[i]==-1){
                ans.push_back(i+s);
            }
        }
        return ans ;

    }
};