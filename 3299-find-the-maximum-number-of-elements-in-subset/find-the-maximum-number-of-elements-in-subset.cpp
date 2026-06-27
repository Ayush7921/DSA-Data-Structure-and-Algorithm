class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<long long , int > mp;
        for (int i=0 ; i<n ; i++ ){
            mp[nums[i]]++;
        }

        int ans =INT_MIN ;
        for(int i =0 ; i<n ; i++){
          
            int val =1;
            if(nums[i]==1){
                int n=mp[nums[i]];
                if(n%2==1){ ans = max(ans,n);}
                else{ ans = max(ans , n-1);}
            }
            else{

                int num = nums[i];
                while(mp[num]>=2 && mp.contains(pow(num,2))){
                    val = val +2;
                    num = pow(num,2);
                }

                ans = max(ans , val);
            }
        }
        return ans ;
    }
};