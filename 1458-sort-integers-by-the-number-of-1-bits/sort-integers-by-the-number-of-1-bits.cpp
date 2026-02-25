class Solution {
public:
    static int cnt_set(int n){
        int cnt=0;
        for(int i=0;i<32;i++){
            if(n&1)cnt++;
            n>>=1;
        }
        return cnt;
    }
    static bool compare(int a,int b){
        int cnt_a=cnt_set(a);
        int cnt_b=cnt_set(b);
        if(cnt_a!=cnt_b)return cnt_a<cnt_b;
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;

        

        
    }
};