class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int i = 0 ;
        int n = s.size();
        int j = s.size()-1;
        
        int count= 0 ;
        while(i<n){
            if(s[i]=='1'){
                i++;
                count++;
            }else{
                break;
            }
        }

        while(j>=0){
            if(s[j]=='1'){
                j--;
                count++;
            }else{
                break;
            }
        }

        if(i>=j){
            if(i==j) return (s[i]==1)?count+1 : count ;

            return n ;
        }

        int c1=0;

        for(int k= i ; k<= j ; k++){
            if(s[k]=='1'){
                c1++;
            }
        }

        if(c1==0){
            return count;
        }

        if(c1==1){
            return n;
        }

        

        int pc = 0;
        int fc=0;
        bool flag = false ;
        int c= 0;

        while(i<=j){

            if(s[i]=='0'){
                if(flag){
                    fc++;
                }else{
                    pc++;
                }

                i++;

            }else{

                if(flag){
                    c=max(c,fc+pc+c1);
                    i++;
                    while(s[i]=='1'){i++;}
                    pc=fc;
                    fc=0;
                }
                else{
                    flag = true;
                    i++;
                    while(s[i]=='1'){i++;}

                }
            }

        }
    
        

        if(flag){
            c = max(c , fc+pc+c1);
        }

        return count+c;
        
    }
};