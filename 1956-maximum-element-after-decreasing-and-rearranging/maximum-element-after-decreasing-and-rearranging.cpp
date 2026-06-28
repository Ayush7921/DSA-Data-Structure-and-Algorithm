class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();

        sort(arr.begin(), arr.end());

        if(arr[0] != 1){
            arr[0] = 1;
        }

        for(int i = 1; i < n;  i++){

            if(abs(arr[i] - arr[i - 1]) > 1){
                arr[i] = arr[i - 1] + 1;
            }
        }

        int ans = 0;

        for(int i  = 0; i < n; i++){
            ans = max(ans, arr[i]);
        }

        return ans;
    }
};