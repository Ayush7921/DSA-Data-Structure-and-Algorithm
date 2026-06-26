class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int > mp;
        mp[0]=1;
        long long ans=0;
        int sum=0;
        long long validpoints=0;

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