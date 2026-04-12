class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);
        for(auto query:shifts){
            int start=query[0];

            int end=query[1];
            int val=query[2];
            diff[start]+=val==0?-1:1;
            if(end+1<n)diff[end+1]-=val==0?-1:1;


        }
        for(int i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];

        }
        for(int i=0;i<n;i++){
            int shift=diff[i]%26;
            s[i]=((s[i]-'a'+shift+26)%26)+'a';

        }
        return s;


        
    }
};