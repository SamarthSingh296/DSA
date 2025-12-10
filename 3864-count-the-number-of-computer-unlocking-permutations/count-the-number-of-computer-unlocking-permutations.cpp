class Solution {
    int M=1e9+7;
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        long long ans=1;
            for(int i=1;i<n;i++){
                if(complexity[i]<=complexity[0])return 0;
                else ans=(ans*i)%M;
            }

        
        return ans;
        
    }
};