class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,int>>>mat(m,vector<pair<int,int>>(n,{0,0}));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=grid[i][j]=='X';
                int y=grid[i][j]=='Y';
                mat[i][j]={x,y};
                if(i>0){
                    mat[i][j].first+=mat[i-1][j].first;
                     mat[i][j].second+=mat[i-1][j].second;
                }

                if(j>0){
                    mat[i][j].first+=mat[i][j-1].first;
                    mat[i][j].second+=mat[i][j-1].second;

                }
                if(i>0&&j>0){
                    mat[i][j].first-=mat[i-1][j-1].first;
                    mat[i][j].second-=mat[i-1][j-1].second;
                }

                
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cntx=mat[i][j].first;
                int cnty=mat[i][j].second;
                if(cntx==cnty&&cntx>0)ans++;
            }
        }
        return ans;
        

    }
};