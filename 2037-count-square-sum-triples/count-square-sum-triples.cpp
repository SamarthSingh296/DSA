class Solution {
public:
    int countTriples(int n) {
        set<int>st;
        for(int i=1;i<=n;i++){
            int x=i*i;
            st.insert(x);

        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int k=i;k<=n;k++){
                int sum=i*i+k*k;
                if(st.find(sum)!=st.end())cnt++;

            }
        }
        return 2*cnt;


        
        
    }
};