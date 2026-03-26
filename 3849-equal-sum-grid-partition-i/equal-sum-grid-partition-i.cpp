class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        long long tot_sum=0;
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tot_sum+=grid[i][j];
            }
        }
        if(tot_sum%2!=0)return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[j][i];
            }
            if(sum==tot_sum/2)return true;
        }
        long long horiz_sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                horiz_sum+=grid[i][j];
            }
            if(horiz_sum==tot_sum/2)return true;
        }
        return false;
    }
};