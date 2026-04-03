class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int orig=x;
        long long sum=0;
        while(orig>0){
            int rem=orig%10;
            sum=sum*10+rem;
            orig/=10;

        }
        if(sum==x)return true;
        else return false;
        
    }
};