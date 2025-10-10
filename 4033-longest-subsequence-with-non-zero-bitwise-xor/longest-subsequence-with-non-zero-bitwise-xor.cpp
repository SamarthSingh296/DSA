class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        if(n==0)return 0;
        int x=0;
        int len=0;
        for(int l:nums)x^=l;
        if(x!=0)return n;
        bool flag=true;
        for(int l:nums){
            if(l!=0){
                flag=false;
                break;
            }
        }
        if(flag)return 0;
        return n-1;
        
    }
};