class Solution {
public:
    int m,n,res;
    int non_obstacle;
    void backtrack(vector<vector<int>>& grid,int cnt,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==-1)return;
        if(grid[i][j]==2){
            if(cnt==non_obstacle)res++;
            return ;
        }
         grid[i][j]=-1;
        backtrack(grid,cnt+1,i-1,j);
        backtrack(grid,cnt+1,i+1,j);
        backtrack(grid,cnt+1,i,j-1);
        backtrack(grid,cnt+1,i,j+1);
        grid[i][j]=0;




    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int start_x=0,start_y=0;
        non_obstacle=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)non_obstacle++;
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
            }
        }
        non_obstacle++;
        backtrack(grid,0,start_x,start_y);
        return res;


        
    }
};