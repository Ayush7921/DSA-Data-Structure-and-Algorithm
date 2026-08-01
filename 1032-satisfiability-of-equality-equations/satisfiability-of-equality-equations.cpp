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

    bool equationsPossible(vector<string>& equations) {
        parent.assign(26,0);
        for(int i = 0 ; i< 26 ; i++){
            parent[i]=i;
        }
        rank.assign(26,0);

        for(string &s : equations)
        {
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        for(string &s : equations){

            if(s[1]=='!'){
                int x = find(s[0]-'a');
                int y = find(s[3]-'a');

                if(x==y){
                    return false;
                }
            }
        }

        return true ;
    }
};