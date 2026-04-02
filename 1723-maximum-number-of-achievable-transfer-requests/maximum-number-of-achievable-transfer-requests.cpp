class Solution {
public:
    int ans=0;
    void solve(int i,vector<vector<int>>& requests,vector<int>&balance,int cnt){
        if(i>=requests.size()){
            for(int it:balance){
                if(it!=0)return ;
            }
            ans=max(ans,cnt);
            return ;
        }
            int from=requests[i][0];
            int to=requests[i][1];
            balance[from]--;
            balance[to]++;
            solve(i+1,requests,balance,cnt+1);
            balance[from]++;
            balance[to]--;
            solve(i+1,requests,balance,cnt);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>balance(n,0);
        solve(0,requests,balance,0);
        return ans;
        
    }
};