class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count =0;
        for(int  i = 0 ; i< patterns.size() ; i++ ){
            if(word.find(patterns[i])== string::npos){
                count += 0;
            }
            else{
                count += 1;
            }
        }
        return count ;
    }
};