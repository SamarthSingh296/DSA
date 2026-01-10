class Solution {
public:
int t[201][20001];
   bool solve(int ind,int target,vector<int>&nums){
    if(target==0)return true;
    if(ind==0)return (nums[0]==target);
    if(t[ind][target]!=-1)return t[ind][target];
    bool not_take=solve(ind-1,target,nums);
    bool take=false;
    if(nums[ind]<=target)take=solve(ind-1,target-nums[ind],nums);
    return t[ind][target]=take|not_take;

   }
    bool canPartition(vector<int>& nums) {
        int tot_sum=accumulate(nums.begin(),nums.end(),0);
        memset(t,-1,sizeof(t));
        if(tot_sum%2!=0)return false;
        int target=tot_sum/2;
        int n=nums.size();
        return solve(n-1,target,nums);

        

    }
};