class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size()-1;
        stack<pair<int , int>> s;

        vector<int> ans(n+1,0);
        for(int i = n ; i>=0 ; i--){
            int day=0;
            while(!s.empty() && temperatures[i] >= s.top().first  ){
                day+=s.top().second;
                s.pop();
            }
            if(s.empty()) day=0;
            else{ day +=1 ;}

            s.push({temperatures[i],day});
            ans[i]=day;
        }
        return ans;
    }
};