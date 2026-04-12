class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int>diff(n,0);
        for(auto query:queries){
            int start=query[0];
            int end=query[1];
            diff[start]+=1;
            if(end+1<n)diff[end+1]-=1;
        }
        for(int i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];
        }
        for(int i=0;i<n;i++){
            if(diff[i]<nums[i])return false;
        }
        return true;

        
    }
};