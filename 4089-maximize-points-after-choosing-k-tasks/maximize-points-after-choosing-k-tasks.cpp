class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        vector<pair<int,int>>diff;
        for(int i=0;i<n;i++){
            int loss=technique2[i]-technique1[i];
            diff.push_back({loss,i});
        }
        sort(diff.begin(),diff.end());
        long long ans=0;
        for(int j=0;j<k;j++){
            int idx=diff[j].second;
            ans+=technique1[idx];
        }
        for(int j=k;j<n;j++){
            int idx=diff[j].second;
            ans+=max(technique1[idx],technique2[idx]);
        }
        return ans;
        
    }
};