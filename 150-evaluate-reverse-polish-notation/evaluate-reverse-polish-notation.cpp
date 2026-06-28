class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto c : tokens){
            if(c == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(c == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            }
            else if(c == "+"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(c == "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            }
            else
                st.push(stoi(c));
        }

        return st.top();
    }
};