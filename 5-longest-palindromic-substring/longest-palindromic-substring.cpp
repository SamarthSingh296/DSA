
class Solution {
public:
    int expand(string &s,int left,int right){
        while(left>=0&&right<=s.size()&&s[left]==s[right]){
            left--,right++;

        }
        return right-left-1;
    }
     string longestPalindrome(string s) {
        int max_len=INT_MIN;
        int n=s.size();
        int start;
        for(int i=0;i<n;i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int curr_len=max(len1,len2);

            if(curr_len>max_len){
                max_len=curr_len;
                start=i-(curr_len-1)/2;

            }
            

            

        }
        return s.substr(start,max_len);
        
             
    }
};