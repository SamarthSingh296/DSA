class Solution {
public:
int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        // int cnt=0;
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         if(sum%2!=0)cnt++;
        //     }
        //     }
        
        // return cnt;
        int evencnt=1;
        int oddcnt=0;
        int cnt=0;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
        
            sum+=arr[i];
            if(sum%2==0){
                cnt=(cnt+oddcnt)%M;
                evencnt++;
            }

            else {
                cnt=(cnt+evencnt)%M;
                oddcnt++;
            }
        }
        return cnt;
        
    }
};