class Solution {
public:
    int reverseINT(int x){
        int rev_num=0;
        while(x>0){
            rev_num=rev_num*10+x%10;
            x=x/10;
        }
        return rev_num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>first;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int rev=reverseINT(nums[i]);
            if(first.count(rev))ans=min(ans,first[rev]-i);
            first[nums[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
        
        
    }
};