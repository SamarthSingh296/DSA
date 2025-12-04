class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x:nums)mpp[x]++;
        int cnt=0;
        if(k==0){
            for(auto it:mpp){
                if(it.second>1)cnt++;
            }
        }
        else{
        for(auto it:mpp){
            if(mpp.count(it.first+k))cnt++;
        }
        }
        return cnt;
        
    }
};