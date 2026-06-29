class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        unordered_set<int> set;

        for (int i =0 ; i< s.size() ; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    set.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            set.insert(st.top()) ;
            st.pop();
        }

        string ans;

        for(int i =0 ; i<s.size();i++){
            if(set.find(i) == set.end()){
                ans.push_back(s[i]);
            }
        }

        return ans ;
    }
};