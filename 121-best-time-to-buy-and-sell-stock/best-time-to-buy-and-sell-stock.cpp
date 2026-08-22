class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ls = p[0] ;
        int ms = 0 ;

        for(int i= 1 ; i< p.size() ; i++){
            if(p[i]<ls){
                ls=p[i];
            }else{
                ms = max(ms , p[i]-ls);
            }
        }

        return ms ;
    }
};