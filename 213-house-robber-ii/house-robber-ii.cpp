class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        // if(n==1)return nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int t=nums[i];
            if(i>1)t=nums[i]+prev2;
            int nt=prev;
            int curri=max(t,nt);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
    }

    int rob(vector<int>& num) {
        int l=num.size();
        if(l==1) return num[0];
        vector<int>temp1,temp2;
        for(int i=0;i<l;i++){
            if(i!=0)temp1.push_back(num[i]);
            if(i!=l-1)temp2.push_back(num[i]);
        }
        return max(rob1(temp1),rob1(temp2));
        
        
    }
};