class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        int cnt=0;
        int n=nums.size();

        while(i<n && nums[i]==0)i++;
        for(int j=i+1;j<n;j++){
            if(nums[j]==0)cnt++;
            else{
                if(cnt<k)return false;
                cnt=0;
            }
        }
        return true;
        
    }
};