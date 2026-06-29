class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> ans ;

        for(int i =0 ; i< n ; i++){
            
            while(ans.size()!=0 && ans.back()>0 && ast[i]<0  )
            {
                if(abs(ans.back()) < abs(ast[i])){
                    ans.pop_back();
                }
                else if(abs(ans.back())> abs(ast[i]))
                {
                    ast[i]=0;
                }
                else {
                    ans.pop_back();
                    ast[i]=0;
                }
                   
            }
            if(ast[i]!=0){
                    ans.push_back(ast[i]);
            }
            
        }
        return ans;

    }
};