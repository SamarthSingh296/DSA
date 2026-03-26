class Solution {
public:
    vector<int>get_nse(vector<int>&arr,int n){
        stack<long long>st;
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
        stack<long long>st;
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

    long long sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        if(n==0)return 0;
        vector<int>nse=get_nse(arr,n);
        vector<int>pse=get_pse(arr,n);
        long long res=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long sum=(left)*(right)*(arr[i]);
            res=(res+sum);

        }
        return res;
    }
    vector<int>get_nge(vector<int>&arr,int n){
        stack<long long>st;
        st.push(n-1);
        vector<int>res(n);
        res[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i])st.pop();
            if(st.empty())res[i]=n;
            else res[i]=st.top();
            st.push(i);

        }

        return res;
    }
    vector<int>get_pge(vector<int>&arr,int n){
        stack<long long>st;
        st.push(0);
        vector<int>res(n);
        res[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty()&&arr[st.top()]<arr[i])st.pop();
            if(st.empty())res[i]=-1;
            else res[i]=st.top();
            st.push(i);

        }

        return res;
    }
    long long sumSubarrayMaxi(vector<int>& arr) {
        
        int n=arr.size();
        if(n==0)return 0;
        vector<int>nge=get_nge(arr,n);
        vector<int>pge=get_pge(arr,n);
        long long res=0;
        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            long long sum=(left)*(right)*(arr[i]);
            res=(res+sum);

        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxi(nums)-sumSubarrayMins(nums);
        
    }
};