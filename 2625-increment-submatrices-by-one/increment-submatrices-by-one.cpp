class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(auto query:queries){
            int start_row=query[0];
            int end_row=query[2];
            int start_col=query[1];
            int end_col=query[3];
            mat[start_row][start_col]+=1;
            mat[start_row][end_col+1]-=1;
            mat[end_row+1][start_col]-=1;
            mat[end_row+1][end_col+1]+=1;
            }
            for(int i=0;i<n;i++){
                for(int j=1;j<n;j++){
                    mat[i][j]+=mat[i][j-1];
                }
            }
              for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]+=mat[i-1][j];
                }
            }
            vector<vector<int>>res(n,vector<int>(n));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    res[i][j]=mat[i][j];
                }
            }
        
        return res;
        
    }
};