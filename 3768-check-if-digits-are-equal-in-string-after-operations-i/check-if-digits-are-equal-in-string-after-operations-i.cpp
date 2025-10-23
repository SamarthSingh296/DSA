class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        int l=n;
        while(l>2){
            for(int i=0;i<l-1;i++){
                s[i]=(s[i]+s[i+1])%10;

            }
            l--;

        }
        if(s[0]==s[1]){
            return true;
        }
        else return false;
        
    }
};