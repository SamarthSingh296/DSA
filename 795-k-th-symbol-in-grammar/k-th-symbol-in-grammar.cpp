class Solution {
public:
    int kthGrammar(int n, int k) {
    vector<int>dp(n+1,-1);
    int len=pow(2,n-1);
    int mid=len/2;
    if(dp[n]!=-1)return dp[n];
    if(n==1&&k==1)return 0;
    if(k<=mid)dp[n]= kthGrammar(n-1,k);
    else dp[n]= 1-kthGrammar(n-1,k-mid);
    return dp[n];

        
        
    }
};