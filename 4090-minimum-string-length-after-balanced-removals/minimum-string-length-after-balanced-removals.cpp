class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnt_a=0,cnt_b=0;
        for(char c:s){
            if(c=='a')cnt_a++;
            else cnt_b++;
        }
        return abs(cnt_a-cnt_b);
    }
};