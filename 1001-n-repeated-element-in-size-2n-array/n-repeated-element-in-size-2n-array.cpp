class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int>mpp;
        for(auto i:nums)mpp[i]++;
        for(auto it:mpp){
            if(it.second>1)return it.first;
        }
        return -1;
        
    }
};