class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1){return nums[0];}
        int a=0;
        int b =0;
        for(int i = 1; i<=n-1;i++){
            int steal = nums[i-1] + a ;
            int skip = b ;

            a=b;

            b= max(steal,skip);
        }

      
        int c=0;

        int d=0;
        for(int i = 2; i<=n;i++){
            int steal = nums[i-1] + c ;
            int skip = d;
            c=d;
            d= max(steal,skip);
        }


        return max(b,d);

    }
};