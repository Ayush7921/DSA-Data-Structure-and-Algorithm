class Solution {
public:
    int Color;
    int c;
    int m ;
    int n ;
    void dfs (vector<vector<int>>& image , int sr , int sc){
        int  i = sr ;
        int j = sc ;
        image[i][j]=Color;

        vector<int> deltarow={-1,0,1,0};
        vector<int> deltacol={0,1,0,-1};

        for(int k = 0 ; k<4; k++){
            int newrow = i+deltarow[k];
            int newcol = j + deltacol[k];

            if((newrow>=0 && newrow <m ) && (newcol>=0 && newcol <n ) && image[newrow][newcol]==c){
                dfs(image ,newrow,newcol);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        c  = image[sr][sc];
        Color = color;
        if(c == Color){
            return image;
        }
        
        m = image.size();
        n = image[0].size();
        dfs(image , sr , sc );
        return image ;
    }
};