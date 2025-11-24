class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>res;
        int curr=0;
        for(int num:nums){
            curr=((curr<<1)+num)%5;
            res.push_back(curr%5==0);
        }
return res;
        
        
    }
};