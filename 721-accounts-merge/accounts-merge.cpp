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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int r = accounts.size();
        parent.assign(r, 0) ;
        rank.assign(r,0);
        for(int i = 0 ; i< r ; i++) parent[i]=i;
        map<string,int> mp ;

        for(int i = 0 ; i< r; i++){
            for(int j = 1 ; j< accounts[i].size() ; j++){
                if(mp.contains(accounts[i][j])){
                    Union(i,mp[accounts[i][j]]);
                }else{
                    mp[accounts[i][j]]=i;
                }
            }
        }

        unordered_map<int , vector<string>> m;

        for(auto & it : mp){
            int p = find(it.second);
            m[p].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        for(auto &it : m){
            int root = it.first;
            vector<string> account = {accounts[root][0]}; 

            account.insert(account.end(), it.second.begin(), it.second.end());
            ans.push_back(account);
        }

        return ans ;
        
    }
};