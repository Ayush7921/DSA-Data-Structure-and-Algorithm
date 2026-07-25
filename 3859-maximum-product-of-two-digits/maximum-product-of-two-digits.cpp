class Solution {
public:
    int maxProduct(int n) {

        int maxdigit = 0 ;
        int secondmaxdigit = 0 ;
        

        while(n){

            int x = n%10;
            
            if( x> maxdigit){
                secondmaxdigit = maxdigit;
                maxdigit = x;
            }else if( x>secondmaxdigit){
                secondmaxdigit = x ;
            }

            n=n/10;
        }

        return maxdigit * secondmaxdigit ;
    }
};