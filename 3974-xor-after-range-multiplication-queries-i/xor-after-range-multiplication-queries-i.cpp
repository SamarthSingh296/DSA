class Solution {
public:
    int MOD=1e9+7;
    int Xor(vector<int>&nums){
        int xorr=0;
        for(int i:nums){
            xorr^=i;
        }
        return xorr;
    }
    void Update(vector<int>&nums,int li,int ri,int ki,int vi){
        while(li<=ri){
           nums[li]=(1LL*nums[li]*vi)%MOD;

            li+=ki;
        }
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for(int i=0;i<queries.size();i++){
            int  li=queries[i][0];
            int ri=queries[i][1];
            int ki=queries[i][2];
            int vi=queries[i][3];
            Update(nums,li,ri,ki,vi);
        }
        return Xor(nums);
    }
        



};