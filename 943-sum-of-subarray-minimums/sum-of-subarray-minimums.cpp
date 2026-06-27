class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n= arr.size();
        int mod = 1e9 + 7 ;

        stack<pair<int , int >> s;

        vector<int> lmn(n,-1);

        for (int i = 0 ; i< n ; i++){
            int num = arr[i];

            while(!s.empty() && num < s.top().first){
                s.pop();
            }

            if(!s.empty()){
                lmn[i]=s.top().second;
            }

            s.push({num , i});
        }
        while(!s.empty()){
            s.pop();
        }
      
        vector<int> rmn(n,n);

        for (int i = n-1 ; i>=0 ; i--){
            int num = arr[i];

            while(!s.empty() && num <= s.top().first){
                s.pop();
            }

            if(!s.empty()){
                rmn[i]=s.top().second;
            }

            s.push({num , i});
        }
        while(!s.empty()){
            s.pop();
        }

        long long result = 0 ;

        for(int i =0 ;i< n ; i++){
            int left = abs(i - lmn[i]);
            int right = abs(i - rmn[i]);

            result = (result + 1LL * left * right * arr[i]) % mod;
        }
        return result % mod ;







    }
};