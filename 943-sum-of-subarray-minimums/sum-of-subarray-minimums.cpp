class Solution {
public:
    int mod=1e9+7;
    vector<int>get_nse(vector<int>&arr,int s){
        int n=arr.size();
        stack<int>st;
        st.push(n-1);
        vector<int>res(n);
        res[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i])st.pop();
            if(st.empty())res[i]=n;
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;

    }
     vector<int>get_pse(vector<int>&arr,int n){
        stack<int>st;
        st.push(0);
        vector<int>res(n);
        res[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i])st.pop();
            if(st.empty())res[i]=-1;
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;

    }

    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        if(n==0)return 0;
        vector<int>nse=get_nse(arr,n);
        vector<int>pse=get_pse(arr,n);
        long long res=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long sum=(left%mod)*(right%mod)*(arr[i]%mod)%mod;
            res=(res+sum)%mod;

        }
        return res;
    }
};