class Solution {
public:

    // int rotate_sum(vector<int>&nums){
    //     int k=nums.size();
    //     int res=INT_MIN;
    //     vector<int>original=nums;
    //     while(k>0){
    //     int sum=0;
    //     nums=original;
    //     reverse(nums.begin(),nums.end());
    //     reverse(nums.begin(),nums.begin()+k);
    //     reverse(nums.begin()+k,nums.end());
    //     for(int i=0;i<nums.size();i++){
    //         sum+=i*nums[i];

    //     }
    //     res=max(res,sum);
    //     k--;

    //     }
    //     return res;

    // }
    int maxRotateFunction(vector<int>& nums) {
        int f0=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f0+=i*nums[i];
        }
        long long res=f0;
        long long prev=f0;
        for(int k=1;k<n;k++){
            long long  curr=prev+sum-n*nums[n-k];
            res=max(res,curr);
            prev=curr;


        }
        return res;
    }
        
    
};