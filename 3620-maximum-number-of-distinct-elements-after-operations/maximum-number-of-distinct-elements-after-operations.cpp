class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0,prevmax=INT_MIN;
        for(int n:nums){
            int lower_bound=n-k;
            int upper_bound=n+k;
            if(prevmax<lower_bound){
                prevmax=lower_bound;
                cnt++;
            }
            else if(prevmax<upper_bound){
                prevmax++;
                cnt++;
            }
        }
        return cnt;
    }
};