class Solution {
public:
    int n;
    int dp[101][101];
    bool vistaar(int i,string &s,int balance){
        if(balance<0)return false;
        if(dp[i][balance]!=-1)return dp[i][balance];
        if(i==s.size()){
            if(balance==0)return true;
            else return false;
        };
        if(s[i]=='(')return dp[i][balance]=vistaar(i+1,s,balance+1);
        else if(s[i]==')')return dp[i][balance]=vistaar(i+1,s,balance-1);
        else{
            return dp[i][balance]=vistaar(i+1,s,balance+1)||vistaar(i+1,s,balance-1)||vistaar(i+1,s,balance);
        }

    }
    bool checkValidString(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return vistaar(0,s,0);

        
    }
};