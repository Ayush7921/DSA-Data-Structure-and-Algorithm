class Solution {
public:
    // vector<int> parent ;
    // vector<int> rank ;
    int find (int i , vector<int > &parent){
        if(i==parent[i]){
            return i ;
        }

        return parent[i]=find(parent[i],parent);
    }
    
    bool Union(int i , int j, vector<int> & rank , vector<int> & parent){
        int x = find(i,parent);
        int y = find(j,parent);

        if(x==y){
            return false;
        }

        if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }

        return true ;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<int> parent1(n+1);
        vector<int> parent2(n+1);
        for(int i = 0 ;i< n+1 ; i++){
            parent1[i]=i;
            parent2[i]=i;
        }

        vector<int>rank1(n+1,0);
        vector<int>rank2(n+1,0);

        int cnt = 0 ;

        for(auto &e : edges){
            if(e[0]==3){
                bool ma =Union(e[1],e[2],rank1,parent1);
                bool mb =Union(e[1],e[2],rank2,parent2); 

                if(!ma && !mb){
                    cnt++;
                }  
            }
        }
        for(auto &e:edges){

            if(e[0]==1){

               if(!Union(e[1], e[2], rank1, parent1)){
                    cnt++;
                }
                
            }

            if(e[0]==2){

                if(!Union(e[1], e[2], rank2, parent2)){
                    cnt++;
                }
  
            }
           
        }

        int c1 = 0 ;
        int c2 = 0;

        for(int i = 1 ; i< n+1 ; i++){
            if(i==parent1[i]){
                c1++;
            }

            if(i==parent2[i]){
                c2++;
            }
        }

        if(c1==1 && c2==1){
            return cnt;
        }

        return -1 ;
       
        
    }
};