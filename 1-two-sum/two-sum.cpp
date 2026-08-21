class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {

        unordered_map<int , int> mp ;

        for(int i = 0 ; i< nums.size(); i++){
            int f = t - nums[i];

            if(mp.find(f)!=mp.end()){
                return {mp[f],i};
            }else{
                mp[nums[i]]=i;
            }
        }

        return {};
        
    }
};