class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r = m.size();
        int c = m[0].size();

        int n = r*c;

        int i = 0 ;
        int j = n-1;

        while(i<=j){
            int mid = i + (j-i)/2 ;

            int cr = mid/c;
            int cc= mid % c;

            int ele = m[cr][cc] ;

            if(ele ==target){
                return true ;
            }else if(ele < target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }

        return false ;
    }
};