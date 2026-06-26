class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int > mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        int validpoints=0;

        for(int i =0 ; i<nums.size() ; i++){
            if(nums[i]== target){
                validpoints+=mp[sum];
                sum+=1;
            }
            else{
                sum-=1;
                validpoints-=mp[sum];
            }

            mp[sum]++;
            ans+=validpoints;
        }
        return ans;
    }
};