class Solution {
public:
    int minimumPushes(string word) {

        int n = word.size();

        int ans = 0 ;

        if(n <= 8 ){
            return n; 
        }else if(n<=16){
            int k = n % 8;
            if(k==0){
                k=8;
            }
            return (8 + (2*k));
        }else if(n<=24){
            int k = n%8;
            if(k==0){
                k=8;
            }
            return (24 + (3*k));
        }else{
            if(n==25){
                return 52;
            }else{
                return 56;
            }
        }

        return 0 ;
        
    }
};