class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> open;
        vector<int> remove;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open.push_back(i);
            } 
            else if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop_back();  
                } else {
                    remove.push_back(i);
                }
            }
        }
        for(int x : open) {
            s[x]='*';
        }
        for(int x : remove) {
            s[x] = '*';
        }

        string ans = "";
        for(char c : s) {
            if(c != '*') ans += c;
        }

        return ans;
    }
};