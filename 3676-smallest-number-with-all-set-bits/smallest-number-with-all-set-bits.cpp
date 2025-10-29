class Solution {
public:
    int smallestNumber(int n) {
        int ans=1;
        if(n>0&&n<=1)ans= 1;
        else if(n>1&&n<=3)ans= 3;
        else if(n>3&&n<=7)ans= 7;
        else if(n>7&&n<=15)ans= 15;
        else if(n>15&&n<=31)ans= 31;
        else if(n>31&&n<=63)ans= 63;
        else if(n>63&&n<=127)ans= 127;
        else if(n>127&&n<=255)ans= 255;
        else if(n>255&&n<=511)ans= 511;
        else ans=1023;
        return ans;


        

    }
};