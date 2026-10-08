class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st ;
        string ans;

        for(auto & c : s ){
            if(st.empty()){
                st.push(c);
            }else{
                if(c=='('){
                    st.push(c);
                }
                else{
                    st.pop();
                }

                if(st.empty()){
                    continue;
                }
                ans+=c;
            }
        }
        return ans;
    }
};