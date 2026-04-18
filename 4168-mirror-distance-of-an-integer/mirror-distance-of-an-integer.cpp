class Solution {
public:
    int rev(int n){
        int reverse=0;
        while(n>0){
            int rem=n%10;
            reverse=reverse*10+rem;
            n/=10;
        }
        return reverse;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));

        
    }
};