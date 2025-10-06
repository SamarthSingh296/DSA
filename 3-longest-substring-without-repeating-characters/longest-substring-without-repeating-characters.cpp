class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map<char,int>mpp;
        int left=0,right=0,len=0;
        while(right<s.length()){
           char ch=s[right];
            if(mpp.find(ch)!=mpp.end()&& mpp[ch]>=left){
                left=mpp[ch]+1;
            }
            mpp[ch]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
        
    
};