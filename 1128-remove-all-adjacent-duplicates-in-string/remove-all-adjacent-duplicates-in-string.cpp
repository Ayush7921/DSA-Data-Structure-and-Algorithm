class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if(n==0 || n==1){
            return s ;
        }

        stack<char> st;

        for(int i = 0 ; i<n ;  i++){
            if(!st.empty() && s[i]==st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
     
        return ans;

    }
};