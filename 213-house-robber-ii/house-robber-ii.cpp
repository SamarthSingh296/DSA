class Solution {
public:
    int dp[101];
    int f(vector<int>& nums,int ind){
        if(ind==0)return nums[ind];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+f(nums,ind-2);
        int notpick=0+f(nums,ind-1);
        return dp[ind]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>zero,first;
        for(int i=0;i<n-1;i++){
            zero.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            first.push_back(nums[i]);
        }
        int n1=zero.size();
        int n2=first.size();
        memset(dp,-1,sizeof(dp));


        int rob0th=f(zero,n1-1);
        memset(dp,-1,sizeof(dp));
        int skip0th=f(first,n2-1);
        return max(rob0th,skip0th);

        
    }
};