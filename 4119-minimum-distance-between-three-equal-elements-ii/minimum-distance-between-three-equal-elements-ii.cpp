class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto &[val,indices]:mpp){
            if(indices.size()<3)continue;
            for(int i=0;i<indices.size()-2;i++){
            ans=min(ans,2*(indices[i+2]-indices[i]));
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};