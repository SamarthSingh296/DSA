/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarysearchinc(int low,int high,MountainArray &mountainArr,int target){
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target)return mid;
            else  if(mountainArr.get(mid)<target)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int binarysearchdec(int low,int high,MountainArray &mountainArr,int target){
       while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target)return mid;
            else  if(mountainArr.get(mid)>target)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
     int peakIndexInMountainArray(MountainArray &mountainArr) {

        int low=0,high=mountainArr.length()-1;
        while(low<high){
            int mid=(low+high)>>1;
            if((mountainArr.get(mid))<mountainArr.get(mid+1))low=mid+1;
            else high=mid;
        }
        return low;

        
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=peakIndexInMountainArray(mountainArr);
        int ans=-1;
        int inc=binarysearchinc(0,peak,mountainArr,target);
        if(inc!=-1)ans= inc;
        int dec=binarysearchdec(peak+1,mountainArr.length()-1,mountainArr,target);
        if(inc==-1&&dec!=-1)ans= dec;
        return ans;
        
        }

        
    
};