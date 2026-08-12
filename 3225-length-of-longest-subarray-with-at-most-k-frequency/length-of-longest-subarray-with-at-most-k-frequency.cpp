class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0 ;
        int j = 0;
        int n = nums.size();
        int len = 0;

        unordered_map<int,int> mp;

        while(j!=n){
            int x = nums[j];
            mp[x]++;

            while(mp[x]>k){

                mp[nums[i]]--;
                i++;

            }

            len = max(len , j-i+1);
            j++;
        }

        return len;
    }
};