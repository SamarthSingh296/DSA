class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            bool changed=false,valid=true;
            for(int i=0;i<s.size();i++){
                if(s[i]=='2'||s[i]=='5'||s[i]=='6'||s[i]=='9')changed=true;
                if(s[i]=='3'||s[i]=='4'||s[i]=='7'){
                    valid=false;
                    break;
                }
                
                
                
            }
            if(valid&&changed)cnt++;

        }
        return cnt;
        
    }
};