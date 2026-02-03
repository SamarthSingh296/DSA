class Solution {
public:
    long long dp[100001][2];
    // long long fun(int ind,int check,vector<int>&nums){
    //     if(ind<0)return 0;
    //     if(dp[ind][check]!=-1)return dp[ind][check];
    //     if(check==0){
    //     long long take=nums[ind]+fun(ind-1,1,nums);
    //     long long skip=fun(ind-1,0,nums);
    //     dp[ind][check]= max(take,skip);
    //     }
    //     else{
    //     long long take=-nums[ind]+fun(ind-1,0,nums);
    //     long long skip=fun(ind-1,1,nums);
    //     dp[ind][check]= max(take,skip);

    //     }
    //     return dp[ind][check];
    // }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        memset(dp,0,sizeof(dp));
        // for(long long i=1;i<n;i++){
        //     dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
        //     dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        // }
        // return max(dp[n-1][0],dp[n-1][1]);
        // // return fun(n-1,0,nums);
        for(long long  i=1;i<=n;i++){
            dp[i][0]=max(nums[i-1]+dp[i-1][1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-nums[i-1],dp[i-1][1]);
        }
        return dp[n][0];
        
            

        }

        
    
};