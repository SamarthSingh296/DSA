class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=0;i<n-1;i++){
            if((abs(prefix[n]-2*prefix[i+1]))%2==0)cnt++;
        }
        return cnt;

        
    }
};