class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans ;
        stack<int> s;
        int j = 0;
        for(int i =1 ; i<=n ; i++){

            s.push(i);
            ans.push_back("Push");

            if(s.top()==target[j]){
                j++;
                if(j>=target.size()){
                    break;
                }

            }
            else{
                s.pop();
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};