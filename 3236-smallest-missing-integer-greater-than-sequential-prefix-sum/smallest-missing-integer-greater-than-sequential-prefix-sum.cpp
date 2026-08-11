class Solution {
public:
    int lookup[52];
    int missingInteger(vector<int>& nums) {
        memset(lookup,0,sizeof(lookup));

        for(int x : nums ){
            lookup[x]=1;
        }
        int prefixsum= nums[0];

        for(int i = 1 ; i< nums.size() ; i++){
            if(nums[i]-nums[i-1]==1){
                prefixsum+=nums[i];
            }else{
                break;
            }
        }
        int ans = prefixsum ;
        for(int i = prefixsum ; i<=51 ; i++){
            if(lookup[i]==0){
                ans=i;
                break;
            }
        }

        return ans ;

        
    }
};