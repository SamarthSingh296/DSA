class Solution {
public:
long long solve(long long t){
    int cnt=0;
    long long sum=0;
    for(int i=2;i<=t/2;i++){
        if(t%i==0){
            cnt++;
            sum+=i;
            if(cnt>4)break;

    }

    }
    if(cnt==2){
        sum+=1+t;
    }
    
    else sum=0;
    return sum;
    
}
    int sumFourDivisors(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(long long num:nums){
            ans+=solve(num);

        }
        return ans;
        
    }
};