class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0 ;
        int n = citations.size();
        int e = n-1;

        int ans = 0 ;

        while(s<=e){
            int mid = s +(e-s)/2;

            if( (n-mid) <=citations[mid]){
                ans = n-mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans ;
    }
};