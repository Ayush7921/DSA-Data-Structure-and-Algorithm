class Solution {
public:
    string removeKdigits(string num, int k) {

        int req=k;
        int n =num.size();

        stack<char> s;

        for(int i =0 ; i< n ; i++){
            while( !s.empty() && req>0  && num[i] - '0' < s.top()-'0'){
                s.pop();
                req--;
            }
            s.push(num[i]);
        }
        while(req>0){
            s.pop();
            req--;
        }

        if(s.empty()){
            return "0";
        }

        string temp;

        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }

        while(temp.size()>1 && temp.back()-'0' == 0){
            temp.pop_back();
        }
        if(temp==""){return "0";}

        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};