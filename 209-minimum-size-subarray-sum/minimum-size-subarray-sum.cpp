class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0;
        int sum=0;
        int res=INT_MAX;
        int n=nums.size();
        while(high<n){
            sum+=nums[high];
            while(sum>=target){
                res=min(res,high-low+1);
                sum-=nums[low];
                low++;
                
            }
            high++;
        }
        if(res!=INT_MAX)return res;
        else return 0;
        
    }
};