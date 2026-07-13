class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        int lowcount= 0;
        int highcount=0;
        int templow=low;
        int temphigh = high ;

        while(templow>0){

            templow/=10;
            lowcount++;

        }

        while(temphigh>0){

            temphigh/=10;
            highcount++;

        }
        

        vector<int> ans ;

        while(lowcount<=highcount){

            int i =1 ;
            int n=0;
            int tempn=0;
            int c = lowcount;
            while(c>0){
                n = n* 10 + i;
                tempn= tempn*10 + 1;
                i++;
                c--;
            }
            int  loop = 10 - lowcount;
            while(loop>0 ){
                if(n>=low && n<=high){
                    ans.push_back(n);
                }

                n = n+tempn;
                loop--;
            }

            lowcount++;



            
        }

        return ans ;

        
    }
};