class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({score[i],i});

        }
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        vector<string>res(n);
        for(int i=0;i<n;i++){
            int j=arr[i].second;
            if(i==0)res[j]="Gold Medal";
            else if(i==1)res[j]="Silver Medal";
            else if(i==2)res[j]="Bronze Medal";
            else res[j]=to_string(i+1);
        }
        return res;


        
    }
};