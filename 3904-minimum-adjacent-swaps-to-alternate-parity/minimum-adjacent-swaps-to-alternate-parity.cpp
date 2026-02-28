class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>store;
        int odd_cnt=0;
        int even_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)odd_cnt++;
            else even_cnt++;
        }
        long long ans=LLONG_MAX;
        if(abs(odd_cnt-even_cnt)>1)return -1;
        if(even_cnt>=odd_cnt){
            store.clear();
            for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)store.push_back(i);
            }
             int j=0;
             long long temp=0;
            for(int nu:store){
                temp+=abs(nu-j);
                j+=2;
            }
            ans=min(ans,temp);
        }
         if(even_cnt<=odd_cnt){
            store.clear();
            for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)store.push_back(i);
            }
            int j=0;
            long long temp=0;
            for(int nu:store){
                temp+=abs(nu-j);
                j+=2;
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};