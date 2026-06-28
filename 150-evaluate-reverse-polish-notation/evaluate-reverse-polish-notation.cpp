class Solution {
public:
    int dooperation(int a , int b , string s){
        if(s=="+"){ return a+b;}
        else if(s=="-"){ return a-b;}
        else if(s=="*"){ return a*b;}
        else { return a/b;}
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i =0 ; i< tokens.size() ; i++){
            if( tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();

                int ans = dooperation(op2,op1,tokens[i]);
                s.push(ans);

            }
            else{
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        int result = s.top();
        return result ;
    }
};