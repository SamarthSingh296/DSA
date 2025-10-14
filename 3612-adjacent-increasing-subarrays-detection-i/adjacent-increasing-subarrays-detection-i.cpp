class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=i+k;
        while(j+k<=n){
            bool first=true,second=true;
            for(int a=i;a<i+k-1;a++){
                if(nums[a]>=nums[a+1]){
                    first=false;
                    break;
                }
            }
            for(int b=j;b<j+k-1;b++){
                if(nums[b]>=nums[b+1]){
                    first=false;
                    break;
                }
        }
        if(first&&second)return true;
        i++;
        j=i+k;
        
    }
    return false;
    }
};