class Solution {
public:
    // int bsearch(vector<int>&nums,int low,int high,int target){
    //      while(low<=high){
    //         int mid=(low+high)>>1;
    //         if(nums[mid]==target){
    //             return mid;
    //         }
    //         else if(nums[mid]>target)high=mid-1;

    //         else{
    //            low=mid+1;
    //         }
    //     }
    //     return -1;
    // }
    int search(vector<int>& a, int target) {
        int n=a.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(a[mid]>a[n-1]){
                if(a[mid]==target)return mid;
                else if(a[mid]<target)low=mid+1;
                else{
                    if(a[0]>target)low=mid+1;
                    else high=mid-1;

                }
            }
            else{
                if(a[mid]==target)return mid;
                else if(a[mid]>target)high=mid-1;
                else {
                    if(a[n-1]<target)high=mid-1;
                    else low=mid+1;
                   
            }
        }
        }
        return -1;
        // int bnd=0;
        // int n=nums.size();
        // int low=0,high=n-1;
        // while(low<=high){
        //     int mid=(low+high)>>1;
        //     if(nums[mid]>nums[n-1]){
        //         low=mid+1;
        //     }
        //     else{
        //         bnd=mid;
        //         high=mid-1;
        //     }
        // }
        
        // int ls=bsearch(nums,0,bnd-1,target);
        // if(ls!=-1)return ls;

        // return bsearch(nums,bnd,n-1,target);
        
    }
};