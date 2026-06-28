class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.size();
        string ans = "/";
        int j = 1;
        
        while(j< n){
            string parts="";
            while(j<n && path[j]!='/'){
                parts.push_back(path[j]);
                j++;    
            }
            ans+=parts;
            if(parts=="."){
                ans.pop_back();
                if(ans.size()>1){
                    ans.pop_back();
                }
            }
            else if(parts ==".." ){
                ans.pop_back();
                ans.pop_back();
                
                if(ans.size()>1){
                     
                     ans.pop_back();
                     while(ans.back()!='/' ){
                         ans.pop_back();
                     }
                     if(ans.size()>1){ans.pop_back();}
                
                
                 }
            }
            
            if(j<n && path[j]==ans.back()){
                ans.pop_back();
            }
            
            if(j<n) ans.push_back(path[j]);
            
            if(j<n) j++;
        
       }
       if(ans.size()>1 &ans.back()=='/') ans.pop_back();
       return ans;
    }
};