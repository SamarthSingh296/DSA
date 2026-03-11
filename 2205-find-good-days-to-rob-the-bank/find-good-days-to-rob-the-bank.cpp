class Solution {
public:
    // bool check_left(vector<int>&nums,int j,int end){
    //     if(j>=end)return true;
    //     if(nums[j]<nums[j+1])return false;
    //     return check_left(nums,j+1,end);

    // }
    //  bool check_right(vector<int>&nums,int j,int end){
    //     if(j>=end)return true;
    //     if(nums[j]>nums[j+1])return false;
    //     return check_right(nums,j+1,end);

    // }
    vector<int> goodDaysToRobBank(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=0;
        right[n-1]=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1])left[i]=left[i-1]+1;
            else left[i]=0;
        }
         for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1])right[i]=right[i+1]+1;
            else right[i]=0;
        }
        vector<int>ans;
        for(int i=t;i<n-t;i++){
            if(left[i]>=t&&right[i]>=t)ans.push_back(i);
        }
        return ans;


    }
};