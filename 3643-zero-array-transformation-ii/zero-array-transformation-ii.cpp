class Solution {
public:
    bool canmakeZero(vector<int>&nums,vector<vector<int>>&queries,int k){
        int n=nums.size();
        
        vector<int>diff(n,0);
        for(int i=0;i<k;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            diff[start]+=val;
            if(end+1<n)diff[end+1]-=val;

            
        }
        for(int i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];
        }
        for(int i=0;i<n;i++){
            if(diff[i]<nums[i])return false;
        }
        return true;





    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canmakeZero(nums,queries,mid)){
                ans=mid;
                r=mid-1;
                
            }
            else l=mid+1;
        }
        return ans;
        

        
        
    }
};