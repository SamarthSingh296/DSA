class Solution {
public:
     int dp[2501][2501];
    int fun(int ind,int prev,vector<int>&nums){
        int n=nums.size();
        if(ind==n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int len=fun(ind+1,prev,nums);
        if(prev==-1||nums[ind]>nums[prev])len=max(len,1+fun(ind+1,ind,nums));
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,-1,nums);
        
    }
};