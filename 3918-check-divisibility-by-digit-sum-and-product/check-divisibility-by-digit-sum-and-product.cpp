class Solution {
public:
    bool checkDivisibility(int n) {
        int x  = n ;
        int p = 1 ;
        int s = 0 ;

        while(n>0){
            int d = n%10;
            p*=d;
            s+=d;
            n/=10;
        }

        return ((x % (p+s))==0);
    }
};