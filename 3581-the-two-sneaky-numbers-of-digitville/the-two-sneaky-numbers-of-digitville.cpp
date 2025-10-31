class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }
        vector<int>res;
        for(auto it:mpp){
            if(it.second>1)res.push_back(it.first);
        }
        return res;
        
    }
};