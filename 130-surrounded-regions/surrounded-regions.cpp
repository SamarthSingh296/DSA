class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)return false;
        return true;
    }
    void dfs(vector<vector<char>>& board,int i,int j,int m,int n){
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(row,col,m,n)&&board[row][col]=='O')dfs(board,row,col,m,n);

        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')dfs(board,0,i,m,n);
        }
         for(int i=0;i<n;i++){
            if(board[m-1][i]=='O')dfs(board,m-1,i,m,n);
        }
         for(int j=0;j<m;j++){
            if(board[j][0]=='O')dfs(board,j,0,m,n);
        }
         for(int j=0;j<m;j++){
            if(board[j][n-1]=='O')dfs(board,j,n-1,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#')board[i][j]='O';
                else board[i][j]='X';
            }
        }
        return ;

        
        
    }
};