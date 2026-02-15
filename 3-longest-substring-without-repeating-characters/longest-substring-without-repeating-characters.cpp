class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        vector<bool>last_seen(256,0);
        int n=s.size();
        int res=0;
        for(int high=0;high<n;high++){
            while(last_seen[s[high]]){
                last_seen[s[low]]=0;
                low++;
            }
            last_seen[s[high]]=1;
            int len=high-low+1;
            res=max(res,len);



        }
        return res;

        
    }
};