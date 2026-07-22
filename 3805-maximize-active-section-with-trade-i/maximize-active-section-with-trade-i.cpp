class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int count1 =0 ;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i]=='1'){
                count1++;
            }
        }

        vector<int> zerotrack;

        for(int i = 0 ; i< s.size();){
            if(s[i]=='0'){
                int count = 0 ;
                while(s[i]=='0'){
                    i++;
                    count++;
                }
                zerotrack.push_back(count);
            }else{
                i++;
            }
        }

        int n = zerotrack.size();

        if(n<=1){
            return count1 ;
        }
        
        int maxzero=0;
        for(int i =0 ; i< n-1 ; i++){
            maxzero=max(maxzero , zerotrack[i]+zerotrack[i+1]);
        }

        return count1+maxzero;
    }
};