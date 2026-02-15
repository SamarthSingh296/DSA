class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int res=0;
        int n=s.size();
        unordered_map<char,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int k=high-low+1;
            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0)f.erase(s[low]);
                low++;
                k=high-low+1;

            }
            int len=high-low+1;
            res=max(res,len);


        }
        return res;
        // int low=0;
        // vector<bool>last_seen(256,0);
        // int n=s.size();
        // int res=0;
        // for(int high=0;high<n;high++){
        //     while(last_seen[s[high]]){
        //         last_seen[s[low]]=0;
        //         low++;
        //     }
        //     last_seen[s[high]]=1;
        //     int len=high-low+1;
        //     res=max(res,len);



        // }
        // return res;

        
    }
};