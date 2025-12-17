bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int n=intervals.size();
        int temp=intervals[0][1];
        for(int i=0;i<n-1;i++){
            if(temp>intervals[i+1][0]){
                cnt++;
            }
            else{
                temp=intervals[i+1][1];
            }
        }
        return cnt;
        
    }
};