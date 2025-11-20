class Solution {
public:
    int kthGrammar(int n, int k) {
        int x=k-1;
        int cnt=0;
        while(x>0){
            x&=x-1;
            cnt++;
        }
        if(cnt%2==0)return 0;
        else return 1;
        
    }
};