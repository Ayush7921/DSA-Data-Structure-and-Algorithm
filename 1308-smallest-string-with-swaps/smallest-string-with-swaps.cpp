class Solution {
public:
    vector<int> parent ;
    vector<int> rank;

    int find (int i){
        if(i==parent[i]){
            return i ;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int i , int j ){
        int x = find(i);
        int y = find(j);

        if(x==y){
            return ;
        }

        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if (rank[x]<rank[y]){
            parent[x]=y;
        }else{
            parent[y]=x;
            rank[x]++;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        unordered_map<int , vector<int>>mp ;

        int n= s.size();
        parent.assign(n,0);
        rank.assign(n,0);
        for(int i = 0 ; i< n ; i++){
            parent[i]=i;
        }

        for(auto &e : pairs){
            Union(e[0],e[1]);
        }
        
        for(int i = 0 ; i< n ; i++){
            int x = find(i);

            if(!mp.contains(x)){
                mp[x]=vector<int>(26, 0);
            }

            mp[x][s[i] - 'a']++;
        }

        for(int i = 0 ; i< n ; i++){
            int x = find(i);

            for(int j = 0 ; j< 26 ; j++){
                if(mp[x][j]!=0){
                    s[i]= j+'a';
                    mp[x][j]--;
                    break;
                }
            }
        }

        return  s;   
    }
};