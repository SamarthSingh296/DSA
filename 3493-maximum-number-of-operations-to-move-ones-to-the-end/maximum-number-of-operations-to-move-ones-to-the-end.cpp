class Solution {
public:
    int maxOperations(string s) {
        int cnt_1=0;
        int op=0;
        int i=0;
        int  n=s.size();
        while(i<n){
            if(s[i]=='0'){
                op+=cnt_1;
                while(i<n&&s[i]=='0')i++;
        }
            else{
                cnt_1++;
                i++;

            
        }
        }
        return op;
        
    }
};