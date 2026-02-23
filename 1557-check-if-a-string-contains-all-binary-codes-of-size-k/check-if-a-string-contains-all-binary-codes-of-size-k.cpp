class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return false;
        unordered_map<string,int>mpp;
        int i=0;
        int n=s.size();
        while(i<n){
            string in=s.substr(i,k);
            i++;

            mpp[in]++;
            if(n-i<k)break;
        }
        cout<<mpp.size()<<endl;
        if(mpp.size()>=pow(2,k))return true;
        else return false;

        
    }
};