class Solution {
public:
    int find(vector<int>&f){
        int maxi=INT_MIN;
        for(int i:f){
            if(i>maxi){
                maxi=i;
            }

        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int low=0;
        int res=0;
        int  n=s.size();
        vector<int>f(256,0);
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int len=high-low+1;
            int max_cnt=find(f);
            int diff=len-max_cnt;
            while(diff>k){
                f[s[low]]--;
                low++;
                len=high-low+1;
                max_cnt=find(f);
                diff=len-max_cnt;

            }
            len=high-low+1;
            res=max(res,len);
            





        }
        return res;


        
    }
};