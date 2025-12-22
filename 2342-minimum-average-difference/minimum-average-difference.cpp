class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       int n=nums.size();
        vector<long long>pref(n);
        long long mini=LLONG_MAX;
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int idx=0;
        for(int i=0;i<n;i++){
            long long leftavg=pref[i]/(i+1);
            long long rightavg=(i==n-1)?0:(pref[n-1]-pref[i])/(n-i-1);
            long long diff=llabs(leftavg-rightavg);
            if(diff<mini){
                mini=diff;
                idx=i;
            }


            }     
            return idx;
        
    }
};