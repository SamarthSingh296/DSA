class Solution {
public:
    int f(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0)return 1;
        if(i==0)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        if(coins[i-1]>amount)return dp[i][amount]=f(i-1,amount,coins,dp);
        else return dp[i][amount]=f(i,amount-coins[i-1],coins,dp)+f(i-1,amount,coins,dp); 

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return f(n,amount,coins,dp);
        
    }
};