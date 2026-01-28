class Solution {
public:
int dp[1001][1001];
    int fun(int ind1,int ind2,string s, string t){
        if(ind1<0||ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s[ind1]==t[ind2]) dp[ind1][ind2]=1+fun(ind1-1,ind2-1,s,t);
         else  dp[ind1][ind2]= max(fun(ind1-1,ind2,s,t),fun(ind1,ind2-1,s,t));
         return dp[ind1][ind2];
       
    }
    int longestCommonSubsequence(string s, string t) {
        // int n=s.size();
        // int m=t.size();
        int n=s.size();
        int m=t.size();
        memset(dp,0,sizeof(dp));
       for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){

            if(s[ind1-1]==t[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
         else  dp[ind1][ind2]= max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
       }




        return dp[n][m];
        
    }
};