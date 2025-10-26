class Solution {
public:
    // int f(vector<int>& nums,int ind,vector<int>&dp){
    //     if(ind==0)return nums[ind];
    //     if(ind<0)return 0;
    //     if(dp[ind]!=-1)return dp[ind];
    //     int pick=nums[ind]+f(nums,ind-2,dp);
    //     int notpick=0+f(nums,ind-1,dp);
    //     return dp[ind]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int t=nums[i];
            if(i>1)t=nums[i]+prev2;
            int nt=prev;
            int curri=max(t,nt);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
    }
};