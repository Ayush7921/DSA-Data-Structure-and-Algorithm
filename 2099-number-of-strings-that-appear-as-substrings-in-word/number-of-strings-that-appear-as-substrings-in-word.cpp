class Solution {
public:
    bool issubstring(string main, string sub) {
    int n = main.size();
    int m = sub.size();

    if (m > n) return false;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && main[i + j] == sub[j]) {
            j++;
        }

        if (j == m)
            return true;
    }

    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int count =0;
        for(int  i = 0 ; i< patterns.size() ; i++ ){
            if(issubstring(word,patterns[i])){
                count += 1;
            }
            else{
                count += 0;
            }
        }
        return count ;
    }
};